/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot13.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:21:25 by znichola          #+#    #+#             */
/*   Updated: 2022/11/23 16:21:25 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	rot13(char c, char pivot)
{
	if (c <= pivot)
		return c + 13;
	else if (c > pivot)
		return c - 13;
	else
		return c;
}

int main(int ac, char ** av)
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
			*str = rot13(*str, 'M');
		else if (*str >= 'a' && *str <= 'z')
			*str = rot13(*str, 'm');
		write (1, str, 1);
		str++;
	}
	

	write(1, "\n", 1);
	return (0);
}