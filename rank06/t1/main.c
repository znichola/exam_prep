#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

void abort()
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

int init_socket(int port)
{
	int sockfd;
	struct sockaddr_in servaddr; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		abort();
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		abort();
	else
		printf("Socket successfully binded..\n");
	if (listen(sockfd, 10) != 0)
		abort();
	return sockfd;
}

struct client {
	int id;
	char *msg;
};

fd_set write_fds, read_fds, master_fds;
int server_fd = 0;
int server_max = 0;
struct client cli[FD_SETSIZE];
int cli_n = 0;

char buf[128];
char rbuf[4096];

void broadcast(int ignore, char *m)
{
	printf("startring broadcast: \"%s\"\n", buf);
	for (int fd = 0; fd < server_max; fd++)
	{
		if (fd != ignore && cli[fd].id != -1 && FD_ISSET(fd, &write_fds))
		{
			printf("to: %d\n", fd);
			send(fd, buf, strlen(buf), 0);
			if (m)
			{
				printf("m: <%s>\n", m);
				send(fd, m, strlen(m), 0);
			}
		}
	}
}

int extract_message(char **buf, char **msg);
char *str_join(char *buf, char *add);

int main(int ac, char **av)
{

	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		return 1;
	}

	server_fd = init_socket(atoi(av[1]));
	server_max = server_fd + 1;
	FD_ZERO(&master_fds);
	FD_SET(server_fd, &master_fds);
	bzero(buf, sizeof(buf));
	for (int i = 0; i < FD_SETSIZE; i++)
	{
		cli[i].id = -1;
		cli[1].msg = NULL;
	}

	while(1)
	{
		write_fds = read_fds = master_fds;
		int set_len = select(server_max, &read_fds, &write_fds, 0, 0);
		if (set_len < 0)
		{
			perror("here");
			abort();
		}
		for (int fd = 0; fd < server_max; fd++)
		{
			if (FD_ISSET(fd, &read_fds)) {
				if (fd == server_fd)
				{
					int connfd = accept(fd, 0, 0);
					if (connfd < 0)
						abort();
					cli[connfd].id = cli_n++;
					FD_SET(connfd, &master_fds);
					server_max = (connfd + 1) >= server_max ? connfd + 1 : server_max;
					bzero(buf, sizeof(buf));
					sprintf(buf, "server: client %d just arrived\n", cli[connfd].id);
					broadcast(connfd, NULL);
				}
				else
				{
					bzero(rbuf, sizeof(buf));
					int res = recv(fd, rbuf, sizeof(rbuf) - 1, 0);
					if (res <= 0)
					{
						close(fd);
						FD_CLR(fd, &master_fds);
						bzero(buf, sizeof(buf));
						sprintf(buf, "server: client %d just left\n", cli[fd].id);
						broadcast(fd, NULL);
						cli[fd].id = -1;
						// if (cli[fd].msg && strlen(cli[fd].msg) > 1)
						// 	cli[fd].msg[0] = '\0';
						// free(cli[fd].msg);
						memset(cli[fd].msg, 0, strlen(cli[fd].msg));
					}
					else
					{
						cli[fd].msg = str_join(cli[fd].msg, rbuf);
						char *msg = NULL;
						while(extract_message(&cli[fd].msg, &msg))
						{
							bzero(buf, sizeof(buf));
							sprintf(buf, "client %d: ", cli[fd].id);
							broadcast(fd, msg);
							free(msg);
						}
					}
				}
				if (--set_len <= 0)
					break;
			}
		}
	}
}

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}