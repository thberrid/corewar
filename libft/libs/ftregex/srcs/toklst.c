/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toklst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:51:17 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/14 20:26:37 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <strings.h>
#include "ftregex/t_token.h"
#include "ftregex/token.h"
#include "ftlib.h"
#include "ftio.h"

void	clear_toklst(t_toklst *lst)
{
	while (lst->size > 1)
	{
		if (lst->size > 1 && (lst->head = lst->head->next))
		{
			free(lst->head->prev);
			lst->size--;
		}
		if (lst->size > 1 && (lst->tail = lst->tail->prev))
		{
			free(lst->tail->next);
			lst->size--;
		}
	}
	free(lst->head);
	ft_bzero(lst, sizeof(t_toklst));
}

t_token	*pop_tok(t_toklst *lst, t_token *tok)
{
	if (!tok)
		return (NULL);
	if (lst->tail == tok)
		lst->tail = tok->prev;
	if (lst->head == tok)
		lst->head = tok->next;
	if (tok->prev)
		tok->prev->next = tok->next;
	if (tok->next)
		tok->next->prev = tok->prev;
	tok->next = NULL;
	tok->prev = NULL;
	--lst->size;
	return (tok);
}

/*
**	inserts the token [tok] into the list [lst] after the token [pos]
**	if [pos] is NULL, the token is added to the end of the list
**	Returns the token [tok] in place in the list
*/

t_token	*insert_after(t_toklst *const lst, t_token *tok, t_token *pos)
{
	if (!pos)
		pos = lst->tail;
	tok->next = NULL;
	tok->prev = pos;
	if (pos)
	{
		tok->next = pos->next;
		pos->next = tok;
	}
	if (tok->next)
		tok->next->prev = tok;
	else
		lst->tail = tok;
	if (tok->prev)
		tok->prev->next = tok;
	else
		lst->head = tok;
	++lst->size;
	return (tok);
}

/*
**	inserts the token [tok] into the list [lst] before the token [pos]
**	if [pos] is NULL, the token is added to the begining of the list
**	Returns the token [tok] in place in the list
*/

t_token	*insert_before(t_toklst *lst, t_token *tok, t_token *pos)
{
	if (!pos)
		pos = lst->head;
	tok->prev = NULL;
	tok->next = pos;
	if (pos)
	{
		tok->prev = pos->prev;
		pos->prev = tok;
	}
	if (tok->next)
		tok->next->prev = tok;
	else
		lst->tail = tok;
	if (tok->prev)
		tok->prev->next = tok;
	else
		lst->head = tok;
	++lst->size;
	return (tok);
}

t_token	*new_token(char c, t_toktpe type)
{
	t_token	*new;

	if (!(new = ft_memalloc(sizeof(t_token))))
		return (NULL);
	new->c = c;
	new->type = type;
	return (new);
}
