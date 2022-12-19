/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:39:16 by znichola          #+#    #+#             */
/*   Updated: 2022/12/19 17:09:01 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	find_first_factor(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0 && i != 1)
		{
			printf("%d*", i);
			return (find_first_factor(n / i));
		}
	}
	return (n);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	int	num = atoi(av[1]);
	if (num < 0)
	{
		write(1, "\n", 1);
		return (0);
	}
	printf("num:%d\n", num);
	int n = num;
	printf("%d\n", find_first_factor(num));
	// if (n != 1)
	// 	printf("%d\n", n);
	return (0);
}