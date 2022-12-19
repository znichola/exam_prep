/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:02:46 by znichola          #+#    #+#             */
/*   Updated: 2022/12/18 14:26:27 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int	sig = 1;
	int	ret = 0;
	
	if (*str == '-')
	{
		sig = -1;
		str++;
	}
	else if (*str == '+')
	{
		sig = 1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= (str_base - 1 + '0'))
			ret = ret * str_base + *str - '0';
		else if (str_base > 10 && *str >= 'A' && *str <= (str_base - 10 - 1 + 'A'))
			ret = ret * str_base + *str - 'A' + 10;
		else if (str_base > 10 && *str >= 'a' && *str <= (str_base - 10 - 1 + 'a'))
			ret = ret * str_base + *str - 'a' + 10;
		else
			break ;
		str++;
	}
	return (ret * sig);
}

int main()
{
	int base = 2;	
	printf("%d\n", ft_atoi_base("0", base));
	printf("%d\n", ft_atoi_base("1", base));
	printf("%d\n", ft_atoi_base("2", base));
	printf("%d\n", ft_atoi_base("3", base));
	printf("%d\n", ft_atoi_base("4", base));
	printf("%d\n", ft_atoi_base("5", base));
	printf("%d\n", ft_atoi_base("6", base));
	printf("%d\n", ft_atoi_base("8", base));
	printf("%d\n", ft_atoi_base("9", base));
	printf("%d\n", ft_atoi_base("a", base));
	printf("%d\n", ft_atoi_base("b", base));
	printf("%d\n", ft_atoi_base("c", base));
	printf("%d\n", ft_atoi_base("d", base));
	printf("%d\n", ft_atoi_base("e", base));
	printf("%d\n", ft_atoi_base("f", base));
	printf("%d\n", ft_atoi_base("g", base));
	printf("%d\n", ft_atoi_base("ff", base));
}