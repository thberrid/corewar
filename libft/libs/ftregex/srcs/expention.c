/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expention.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:59:10 by abaurens          #+#    #+#             */
/*   Updated: 2019/07/15 08:52:10 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftregex.h"
#include "ftlib.h"
#include "ftio.h"

static t_token	*expand(t_toklst *lst, t_token *cur, char from, char to)
{
	t_token		*new;

	while (++from < to)
	{
		if (!(new = new_token(from, CHAR)))
			return (NULL);
		cur = insert_after(lst, new, cur);
		if (!(new = new_token(RE_C_OR, OP)))
			return (NULL);
		cur = insert_after(lst, new, cur);
	}
	return (cur);
}

char			expend_dashs(t_toklst *lst)
{
	t_token		*cur;
	char		from;
	char		to;

	cur = lst->head;
	while (cur)
	{
		if (cur->type == OP && cur->c == '-')
		{
			if (!cur->prev || !cur->next)
				return (-2);
			from = cur->prev->c;
			to = cur->next->c;
			if (from > to)
				return (-3);
			cur->c = RE_C_OR;
			if (!(cur = expand(lst, cur, from, to)))
				return (-1);
		}
		cur = cur->next;
	}
	return (0);
}
