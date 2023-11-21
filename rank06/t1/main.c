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

// int max_socket()
// {
// 	int cur = sockfd;
// 	for (int i = 0; i < FD_SETSIZE; i++)
// 		if (cli[i] > cur)
// 			cur = cli[i];
// 	return cur + 1;
// }

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

// int server_max = 0;
// int cli[FD_SETSIZE];



int main(int ac, char **av)
{
	fd_set write_fds, read_fds, master_fds;
	int server_fd = 0;
	int server_max = 0;
	int cli[FD_SETSIZE];
	int cli_n = 0;
	char msg[4096 + 1];
	char buf[4096 + 200];

	void broadcast(int ignore)
	{
		printf("startring broadcast: \"%s\"\n", buf);
		for (int fd = 0; fd < server_max; fd++)
		{
			if (fd != ignore && cli[fd] != -1 && FD_ISSET(fd, &write_fds))
			{
				printf("to: %d\n", fd);
				send(fd, buf, strlen(buf), 0);
			}
		}
	}

	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		return 1;
	}

	server_fd = init_socket(atoi(av[1]));
	server_max = server_fd + 1;
	FD_ZERO(&master_fds);
	FD_SET(server_fd, &master_fds);
	memset(cli, -1, sizeof(cli));

	while(1)
	{
		write_fds = read_fds = master_fds;
		// printf("max %d\n", server_max);
		int set_len = select(server_max, &read_fds, &write_fds, 0, 0);
		if (set_len < 0)
		{
			perror("here");
			abort();
		}
		// printf("set len: %d\n", set_len);
		for (int fd = 0; fd < server_max; fd++)
		{
			if (FD_ISSET(fd, &read_fds)) {
				if (fd == server_fd)
				{
					int connfd = accept(fd, 0, 0);
					if (connfd < 0)
						abort();
					cli[connfd] = cli_n++;
					FD_SET(connfd, &master_fds);
					server_max = (connfd + 1) >= server_max ? connfd + 1 : server_max;
					sprintf(buf, "server: client %d just arrived\n", cli[connfd]);
					broadcast(connfd);
					bzero(buf, sizeof(buf));
				}
				else
				{
					bzero(msg, sizeof(msg));
					int res = recv(fd, msg, sizeof(msg), 0);
					// printf("I got len: %d and msg: %s\n", res, msg);
					if (res <= 0)
					{
						close(fd);
						FD_CLR(fd, &master_fds);
						sprintf(buf, "server: client %d just left\n", cli[fd]);
						broadcast(fd);
						bzero(buf, sizeof(buf));
						cli[fd] = -1;
					}
					else
					{
						msg[res] = '\0';
						sprintf(buf, "client %d: %s", cli[fd], msg);
						broadcast(fd);
						bzero(buf, sizeof(buf));
					}
				}
				if (--set_len <= 0)
					break;
			}
		}
	}
}