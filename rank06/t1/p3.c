#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

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

void abort()
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

int init_sock(int port) {
	int sockfd;
	struct sockaddr_in servaddr; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		abort(); 
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		abort();
	} 
	else
		printf("Socket successfully binded..\n");
	if (listen(sockfd, 10) != 0) {
		abort();
	}
	return sockfd;
}

int cli_max();
void broadcast(int ignore, char *buf, char *msg);

int server_fd = 0;
int server_max = 0;
fd_set r_fd, w_fd, master_fd;
struct client {
	int id;
	char *msg;
};

struct client cli[FD_SETSIZE];

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		return 1;
	}
	server_fd = init_sock(atoi(av[1]));
	server_max = cli_max();
	int cli_n = 0;
	FD_ZERO(&master_fd);
	FD_SET(server_fd, &master_fd);
	char wbuf[128];
	char rbuf[4096];
	bzero(wbuf, 128);
	bzero(rbuf, 4096);
	for (int fd = 0; fd < FD_SETSIZE; fd++)
	{
		cli[fd].id = -1;
		cli[fd].msg = NULL;
	}

	while(1)
	{
		r_fd = w_fd = master_fd;
		server_max = cli_max();
		int set_len = select(server_max, &r_fd, &w_fd, 0, 0);
		for (int fd = 0; fd < server_max; fd++)
		{
			if (FD_ISSET(fd, &r_fd))
			{
				if (fd == server_fd)
				{
					int cfd = accept(fd, 0, 0);
					if (cfd < 0)
						abort();
					cli[cfd].id = cli_n++;
					FD_SET(cfd, &master_fd);
					bzero(wbuf, 128);
					sprintf(wbuf, "server: client %d just arrived\n", cli[cfd].id);
					broadcast(cfd, wbuf, NULL);
				}	
				else
				{
					bzero(rbuf, 4096);
					int res = recv(fd, rbuf, 4096 -1, 0);

					if (res <= 0)
					{
						bzero(wbuf, 128);
						sprintf(wbuf, "server: client %d just left\n", cli[fd].id);
						broadcast(fd, wbuf, NULL);
						cli[fd].id = -1;
						free(cli[fd].msg);
						cli[fd].msg = NULL;
						close(fd);
						FD_CLR(fd, &master_fd);
					}
					else
					{
						cli[fd].msg = str_join(cli[fd].msg, rbuf);
						char *msg = NULL;
						while(extract_message(&cli[fd].msg, &msg))
						{
							bzero(wbuf, 128);
							sprintf(wbuf, "client %d: ", cli[fd].id);
							broadcast(fd, wbuf, msg);
							free(msg);
						}
					}
				}
				if (--set_len >= 0)
					break;
			}
		}
	}

}

int cli_max()
{
	int m = server_fd;
	for (int fd = 0; fd < FD_SETSIZE; fd++)
	{
		if (fd > server_fd && fd > m)
		{
			m = fd;
		}
	}
	return m +1;
}

void broadcast(int ignore, char *buf, char *msg)
{
	printf("sending <%s>\n", buf);
	for (int fd = 0; fd < server_max; fd++)
	{
		if (fd != ignore && fd != server_fd && FD_ISSET(fd, &w_fd))
		{
			printf("to: %d\n", cli[fd].id);
			send(fd, buf, strlen(buf), 0);
			if (msg)
				send(fd, msg, strlen(msg), 0);
		}
	}
}
