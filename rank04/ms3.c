/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:30:43 by znichola          #+#    #+#             */
/*   Updated: 2023/05/25 00:49:52 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


#define EXE ""
#define F ""
#define CDARGS ""
#define CD ""

void put(char *s)
{
	while (*s)
		write(2, s, 1);
}

void err(char *a, char *b)
{
	put(a);
	if (b)
		put(b);
	write(2, "\n", 1);
}

void exit_err(char *a, char *b)
{
	err(a, b);
	exit(1);
}

int is_pipe(char **av)
{
	int i = 0;
	while (av[i])
	{
		if (!strncmp(av[i], "|", 1))
		{
			av[i] = 0;
			return 1;
		}
		if (!strncmp(av[i], ";", 1))
		{
			av[i] =0;
			return 0;
		}
		i++;
	}
	return 0;
}

void ft_cd(char **av)
{
	int i =0;
	while (av[i])
		i++;
	if (i != 2)
		exit_err(CDARGS, 0);
	if (chdir(av[1]))
		exit_err(CD, av[1]);
}

void cmd(int ac, char **av, char **env, int prev, int *fd_prev)
{
	if (ac < 2)
		return ;
	int next = is_pipe(av);
	int fd_next[2];
	int exit_status;
	pid_t pid;
	if (*av)
	{
		if (next && pipe(fd_next) < 0)
			exit_err(F, 0);
		if (!strncmp(*av, "cd", 3))
			ft_cd(av);
		else if ((pid = fork()) < 0)
			exit_err(F, 0);
		else if (pid == 0) // child
		{
			if (prev && dup2(fd_prev[0], 0) < 0)
				exit(-1);
			if (next && dup2(fd_next[1], 1) < 0)
				exit(-1);
			if (execve(*av, av, env) < 0)
				exit_err(EXE, *av);
		}
		else //parent
		{
			if (waitpid(pid, &exit_status, 0) < 0)
				exit_err(F, 0);
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
	int fd_next[2] = {0, 1};
	cmd(ac, av+1, env, 0, fd_next);
	exit(0);
}
