/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:43:25 by znichola          #+#    #+#             */
/*   Updated: 2022/11/23 21:43:25 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void print_bit(unsigned char octet)
{
	for (int i = 7; i >= 0 ; i--)
	{
		if (octet & ( 1U << i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char r;

	r = 0;
	for (int i = 7; i >= 0; i--)
		if (octet & (1U << i))
			r |= (1U << (7 - i));
	return (r);
}

int main(void)
{
	print_bit(0b01000001);
	printf("\n");
	print_bit(reverse_bits(0b01000001));
}