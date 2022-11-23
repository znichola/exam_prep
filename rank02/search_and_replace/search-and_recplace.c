/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search-and_recplace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:39:43 by znichola          #+#    #+#             */
/*   Updated: 2022/11/23 17:39:43 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "unistd.h"

int	main(int ac, char ** av)
{
	printf("args:%d\n", ac);
	if (ac != 4)
	{
		write(1, "\n", 1);
		return(0);
	}
	char	*str = av[1];
	char	a = *av[2];
	char	b = *av[3];
	while (*str)
	{
		if (*str == a)
			*str = b;
		write(1, str, 1);
		str++;
	}
	
	return (0);
}