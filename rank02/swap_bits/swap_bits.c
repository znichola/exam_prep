/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:32:41 by znichola          #+#    #+#             */
/*   Updated: 2022/11/23 21:32:41 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

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

unsigned char	swap_bits(unsigned char octet)
{
	unsigned char left	= octet >> 4U;
	unsigned char right	= octet << 4U;
	print_bits(octet);
	printf("\n");
	print_bits(left);
	printf("\n");
	print_bits(right);
	printf("\n");
	return(left | right);
}

int main(void)
{
	print_bits(swap_bits(0b01000001));
}