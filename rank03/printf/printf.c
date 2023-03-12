/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:52:21 by znichola          #+#    #+#             */
/*   Updated: 2023/02/28 12:59:38 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "printf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


int	put_str(char *str)
{
	int	len = 0;

	if (!str)
		len = write(1, "(null)", 6);
	else
	{
		while (*str)
			len += write(1, str++, 1);
	}
	return (len);
}

int	put_digit(long long num, int base)
{
	char base_str[16] = "0123456789abcdef";
	int len = 0;
	if (num < 0)
	{
		num *= -1;
		len += write(1, "-", 1);
	}
	if (num >= base)
	{
		len += put_digit(num / base, base);
	}
	len += write(1, &base_str[num % base], 1);
	return (len);
}

int	ft_printf(char *fmt, ...)
{
	va_list ap;
	int len = 0;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1))
		{
			fmt++;
			switch(*fmt++)
			{
				case 's':                       /* string */
						len += put_str((char *)va_arg(ap, char *));
						break;
				case 'd':                       /* int */
						len += put_digit((int)va_arg(ap, int), 10);
						break;
				case 'x':                       /* char */
						/* Note: char is promoted to int. */
						len += put_digit((unsigned)va_arg(ap, int), 16);
						break;
			}
		}
		else
		{
			while (*fmt && *fmt != '%')
				len += write(1, fmt++, 1);
		}

	}

	va_end(ap);
	return (len);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (1);
	// char *str = av[1];
	int n = atoi(av[2]);

	char len = printf(av[1], n);
	printf("    res: %d\n", len);
	printf(" my res: %d\n", ft_printf(av[1], n));
	// ft_printf("str:%s, n:%d, p:%p, u:%u\n", "hello 42", -123, "this", 97);
	return (0);
}
