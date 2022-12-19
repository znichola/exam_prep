/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:41:37 by znichola          #+#    #+#             */
/*   Updated: 2022/12/20 00:01:12 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "unistd.h"
#include "stdio.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *tmp;
	
	tmp = lst;
	while(lst->next != NULL)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			int tdata = lst->data;
			lst->data= lst->next->data;
			lst->next->data = tdata;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
