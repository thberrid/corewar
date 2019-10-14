/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:39:50 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/02 18:29:28 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftio/gnl.h"

t_gnl	*get_gnl_bufer_list(void)
{
	static t_gnl	lst = {0, 0};

	return (&lst);
}

t_gnl_e	*get_gnl_bufer(const int fd)
{
	t_gnl	*lst;
	t_gnl_e	*elem;

	lst = get_gnl_bufer_list();
	elem = lst->head;
	while (elem && elem->fd != fd)
		elem = elem->next;
	if (!elem)
	{
		if (!(elem = malloc(sizeof(t_gnl_e))))
			return (NULL);
		elem->fd = fd;
		elem->sv = NULL;
		elem->next = lst->head;
		lst->head = elem;
	}
	return (elem);
}

void	gnl_flush_elem(const t_gnl_e *to_rm)
{
	t_gnl	*lst;
	t_gnl_e	*cur;

	lst = get_gnl_bufer_list();
	if (lst->head == to_rm)
		lst->head = to_rm->next;
	else
	{
		cur = lst->head;
		while (cur && cur->next && cur->next != to_rm)
			cur = cur->next;
		if (cur && cur->next == to_rm)
			cur->next = to_rm->next;
	}
	free((void *)to_rm);
}

void	gnl_flush(const int fd)
{
	t_gnl	*lst;
	t_gnl_e	*cur;
	t_gnl_e	*to_rm;

	to_rm = NULL;
	lst = get_gnl_bufer_list();
	cur = lst->head;
	if (cur && cur->fd == fd)
	{
		to_rm = cur;
		lst->head = cur->next;
	}
	else
	{
		while (cur && cur->next && cur->next->fd != fd)
			cur = cur->next;
		if (cur && cur->next && cur->next->fd == fd)
			to_rm = cur->next;
		if (cur && to_rm)
			cur->next = to_rm->next;
	}
	lst->size -= !!to_rm;
	free(to_rm);
}

void	gnl_clear(void)
{
	t_gnl	*lst;
	t_gnl_e	*cur;

	lst = get_gnl_bufer_list();
	while ((cur = lst->head))
	{
		lst->size--;
		lst->head = cur->next;
		free(cur);
	}
	lst->size = 0;
}
