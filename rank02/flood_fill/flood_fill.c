/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:42:49 by znichola          #+#    #+#             */
/*   Updated: 2022/12/19 22:38:52 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void	ff(char **tab, t_point size, t_point begin, char c)
{

	if (begin.x > size.x - 1 || begin.y > size.y - 1 || begin.x < 0 || begin.y < 0)
		return ;
	if (tab[begin.y][begin.x] == c)
	{
		tab[begin.y][begin.x] = 'F';
		ff(tab, size, (t_point){begin.x - 1, begin.y}, c);
		ff(tab, size, (t_point){begin.x + 1, begin.y}, c);
		ff(tab, size, (t_point){begin.x, begin.y - 1}, c);
		ff(tab, size, (t_point){begin.x, begin.y + 1}, c);
	}
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	ff(tab, size, begin, tab[begin.y][begin.x]);
}