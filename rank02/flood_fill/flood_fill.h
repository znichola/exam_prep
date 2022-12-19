/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:43:43 by znichola          #+#    #+#             */
/*   Updated: 2022/12/19 22:37:58 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOD_FILL
# define FLOOD_FILL

#include "stdio.h"


typedef struct	s_point
{
int				x;
int				y;
}				t_point;

void	flood_fill(char **tab, t_point size, t_point begin);

#endif
