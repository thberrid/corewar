/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nfa_closure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:12:19 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/14 22:44:02 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftregex/nfa.h"
#include "ftlib.h"
#include <stdlib.h>

/*
**	closure NFA operator. Makes this NFA able to repeat itself
**		This op manages the * quantifier
**
**	RES_S----------------\
**		\				  |->RES_E
**	     \->nfa_s=>nfa_e-/
**		  \__________|
*/

t_nfa	*nfa_closure(t_nfa *nfa)
{
	t_nfa	*res;
	int		ln;

	if (!(res = from_epsilon()))
		return (NULL);
	ln = ft_strlen(nfa->name);
	add_epsilon(res->start, nfa->start);
	add_epsilon(nfa->end, res->end);
	add_epsilon(nfa->end, nfa->start);
	if (*nfa->name != '(' && ln > 1)
		res->name[0] = '(';
	ft_strcat(res->name, nfa->name);
	ft_strcat(res->name, *nfa->name != '(' && ln > 1 ? ")*" : "*");
	return (res);
}
