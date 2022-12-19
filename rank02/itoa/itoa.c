/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 07:41:39 by znichola          #+#    #+#             */
/*   Updated: 2022/11/24 08:20:23 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char count_digits(unsigned int n)
{
	int i = 0;
	while (n > 0)
	{
		n /= 10;
		i += 1;
	}
	return (i);
}

char	*recusrive_itoa(unsigned int n, char *s)
{
	if (n > 9)
		s = recusrive_itoa(n / 10, s);
	*s++ = n % 10 + '0';
	*s = '\0';
	// *(++s) = '\0';
	return (s);
}

char	*ft_itoa(int nbr)
{
	unsigned n;
	int sign = 0;
	
	if (nbr < 0)
	{
		n = nbr * -1;
		sign += 1;
	}
	else
		n = (unsigned int)nbr;
	char *s = (char *)malloc((count_digits(n) + 1 + sign) * sizeof(char));
	char *ret = s;
	if (sign)
		*s++ = '-';
	(void)recusrive_itoa(n, s);
	return (ret);
}

int main(void)
{
	int	n = 123;
	printf("my itoa<%s>\n", ft_itoa(n));
	
	for (int i = -100000; i < 100000; i += 788)
	{
		printf("my itoa<%s> ", ft_itoa(i));
		printf(" <%d>\n", i);
	}
}