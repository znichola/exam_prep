/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:13:47 by znichola          #+#    #+#             */
/*   Updated: 2022/12/19 16:36:16 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LSIT
# define FT_LIST

# include <stdlib.h>

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
} 					t_list;

#endif
