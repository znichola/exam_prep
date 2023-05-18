/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:24:28 by znichola          #+#    #+#             */
/*   Updated: 2023/05/18 14:26:35 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

#define CD "error: cd: cannot change directory to "
#define CDARG "error: cd: bad arguments"
#define FATAL "error: fatal"
#define EXE "error: fatal"

void put_str(char *s)
{
	while (*s)
		write(2, s++, 1);
}

void err(char *s, char *a)
{
	put_str(s);
	if (a)
		put_str(a);
	write(2, "\n", 1);
}

void ft_cd(char **av)
{
	int i = 0;
	while(av[i])
		i++;
	if (i != 2)
		err(CDARG, NULL);
	if (chdir(av[1]) < 0)
		err(CD, av[1]);
}

int is_pipe(char **av)
{
	int i = 0;
	while (av[i])
	{
		if (!strncmp(av[i], "|", 2))
		{
			av[i] = NULL;
			return 1;
		}
		if (!strncmp(av[i], ";", 2))
		{
			av[i] = NULL;
			return 0;
		}
		i++;
	}
	return 0;
}

void cmd(int ac, char **av, char **env, int prev, int *fd_prev)
{
	if (ac < 2)
		return ;
	int exit_stat;
	int fd_next[2];
	int next = is_pipe(av);
	pid_t pid;
	if (*av)
	{
		if (next && pipe(fd_next) < 0)
		{
			err(FATAL, NULL);
			exit(1);
		}
		if (!strncmp(*av, "cd", 3))
			ft_cd(av);
		else if ((pid = fork()) < 0)
		{
			err(FATAL, NULL);
			exit(1);
		}
		else if (pid == 0)
		{
			if (prev && dup2(fd_prev[0], 0) < 0)
				exit(-1);
			if (next && dup2(fd_next[1], 1) < 0)
				exit(-1);
			if (execve(*av, av, env) < 0)
			{
				err(EXE, *av);
				exit(1);
			}
		}
		else
		{
			if (waitpid(pid, &exit_stat, 0) < 0)
			{
				err(FATAL, NULL);
				exit(1);
			}
			if (prev)
				close(fd_prev[0]);
			if (next)
				close(fd_next[1]);
		}
	}
	int i = 0;
	while (av[i])
		i++;
	cmd(ac-1-i, av+1+i, env, next, fd_next);
}

int main(int ac, char **av, char **env)
{
	int fd[2] = {0, 1};
	cmd(ac, av+1, env, 0, fd);
	exit(0);
}


/*
	put str
	put err
	is pipe

	cmd ac av env next fd_next

	exit_stat
	next
	fd_next[2]
	pid_t pid

	check ac < 2
	if (*av)
	{
		if pipe
		if cd
		elif command
		elif fork
		elif pid == 0 // parent process!
			if prev make newone
			if next make newone
			if execve
		else
			if wait pids
			if prev cleanup
			if next cleanup
	}
	i = 0
	while (av[i])
		i++;
	cmd (ac-1-i, av+1+i, env, next, fd_next);
*/
