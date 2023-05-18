/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 00:06:26 by znichola          #+#    #+#             */
/*   Updated: 2023/05/18 08:24:56 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define BAD_CD		"error: cd: cannot change directory to "
#define BAD_ARGS	"error: cd: bad arguments"
#define FATAL		"error: fatal"
#define	BAD_EX		"error: cannot execute"

void putstr(char *s)
{
	while (*s)
		write (STDERR_FILENO, s++, 1);
}

void put_error(char *e, char *av)
{
	putstr(e);
	if (av)
		putstr(av);
	write (STDERR_FILENO, "\n", 1);
}

int	is_pipe(char **av)
{
	int ret =0;

	int i = 0;
	while (av[i])
	{
		printf("i:%d\n", i);
		if (!strncmp(av[i], "|", 2))
		{
			ret = 1;
			av[i] = NULL;
			break ;
		}
		if (!strncmp(av[i], ";", 2))
		{
			ret = 0;
			av[i] = NULL;
			break ;
		}
		i++;
	}
	return (ret);
}

void cd(char **av)
{
	int i = 0;
	while (av[i])
		i++;
	if (i != 2)
		put_error(BAD_ARGS, NULL);
	else if (chdir(av[1]) < 0)
		put_error(BAD_CD, av[1]);
}

void cmd(int ac, char **av, char **env, int prev, int *fd_prev)
{
	int fd_next[2];
	int pid;
	int exit_status;

	if (ac < 2)
		return ;
	int next = is_pipe(av);
	printf("cmd\n");
	if (av[0])
	{
		printf("av0\n");
		if (next && pipe(fd_next) < 0)
		{
			put_error(FATAL, NULL);
			exit(1);
		}
		if (!strncmp(av[0], "cd", 3))
			cd(av);
		else if ((pid = fork()) < 0)
		{
			put_error(FATAL, NULL);
			exit(1);
		}
		else if (pid == 0)
		{
			printf("pid=0\n");
			if (prev && dup2(fd_prev[0], 0) < 0)
				exit(-1);
			if (next && dup2(fd_next[1], 1) < 0)
				exit(-1);
			printf("exicuting!\n");
			if (execve(av[0], av, env) < 0)
			{
				put_error(BAD_EX, av[0]);
				exit(1);
			}
		}
		else
		{
			if (waitpid(pid, &exit_status, 0) < 0)
			{
				put_error(FATAL, NULL);
				exit(1);
			}
			if (prev)
				close(fd_prev[0]);
			if (next)
				close(fd_prev[1]);
		}
	}
	printf("finiishcmd\n");
	int i = 0;
	while(av[i])
		i++;
	cmd(ac-1-i, av + 1 + i, env, next, fd_next);
}

int main(int ac, char **av, char **env)
{
	int prev = 0;
	int fd_prev[2] = {0, 1};
	cmd(ac, av+1, env, prev, fd_prev);
	exit(0);
}
