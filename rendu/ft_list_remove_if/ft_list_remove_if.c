/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 21:57:29 by ofedorov          #+#    #+#             */
/*   Updated: 2016/10/09 22:11:03 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (!begin_list || !(*begin_list))
		return ;
	while (cmp((*begin_list)->data, data_ref) == 0)
	{
		*begin_list = (*begin_list)->next;
		if (!(*begin_list))
			return ;
	}
	t_list *cur = *begin_list;
	while (cur && cur->next)
	{
		if (cmp((cur->next)->data, data_ref) == 0)
		{
			cur->next = (cur->next)->next;
		}
		else
			cur = cur->next;
	}
}
