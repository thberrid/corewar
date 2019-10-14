/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 13:06:34 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/12 17:22:51 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftio/ft_types.h"

static int			rm_first(t_ftlist *lst)
{
	t_lst_elem		*rm;

	if (!lst || !lst->tail || !lst->head || !lst->size)
		return (0);
	rm = lst->head;
	lst->head = rm->next;
	if (rm == lst->tail)
		lst->tail = NULL;
	free(rm);
	lst->size--;
	return (0);
}

static int			rm_last(t_ftlist *lst)
{
	t_lst_elem		*rm;

	if (!lst || !lst->tail || !lst->head || !lst->size)
		return (0);
	rm = lst->tail;
	lst->tail = rm->prev;
	if (rm == lst->head)
		lst->head = NULL;
	free(rm);
	lst->size--;
	return (0);
}

void				clear_list(t_ftlist *lst)
{
	while (lst && lst->head && lst->tail && lst->size)
	{
		rm_first(lst);
		rm_last(lst);
	}
}
