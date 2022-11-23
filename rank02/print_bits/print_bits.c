/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:33:28 by znichola          #+#    #+#             */
/*   Updated: 2022/11/23 19:33:28 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
# include<string.h> 

void	print_bits(unsigned char octet)
{
	for (int i = 7; i >= 0; i--)
	{
		if (octet & (1U << i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
}

int	main(int ac, char **av)
{
	print_bits(8);
	return(0);
}