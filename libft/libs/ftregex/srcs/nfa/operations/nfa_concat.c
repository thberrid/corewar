/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nfa_concat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:10:57 by abaurens          #+#    #+#             */
/*   Updated: 2019/07/15 22:11:13 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftregex/nfa.h"
#include "ftlib.h"
#include <stdlib.h>

/*
**	concat the two NFAs together. This match first folowed by second
**		This op manages the classical successions of chars
**
**	RES_S->f_s=>f_e->sec_s=>sec_e->RES_E
*/

t_nfa	*nfa_concat(t_nfa *first, t_nfa *second)
{
	t_nfa	*res;

	if (!(res = ft_memalloc(sizeof(t_nfa))))
		return (NULL);
	add_epsilon(first->end, second->start);
	first->start->is_end = 0;
	res->start = first->start;
	res->end = second->end;
	ft_strcpy(res->name, first->name);
	ft_strcat(res->name, second->name);
	return (res);
}
