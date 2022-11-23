/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:12:12 by znichola          #+#    #+#             */
/*   Updated: 2022/11/23 19:12:12 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "unistd.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	char *str = av[1];
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = ('M' - *str) + 'M' + 1;
		else if (*str >= 'a' && *str <= 'a')
			*str = ('m' - *str) + 'm' + 1;
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
	return (0);
}
