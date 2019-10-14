/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nfa_once.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:12:43 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/16 16:44:16 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftregex/nfa.h"
#include "ftlib.h"
#include <stdlib.h>

/*
**	once NFA operator. Makes the nfa able to repeat itself once it is passed
**		This op manages the + quantifier
**
** RES_S-+->nfa_s=>nfa_e->RES_E
**		  \__________|
*/

t_nfa	*nfa_once(t_nfa *nfa)
{
	t_nfa	*res;

	if (!(res = from_epsilon()))
		return (NULL);
	add_epsilon(res->start, nfa->start);
	add_epsilon(nfa->end, res->end);
	add_epsilon(nfa->end, nfa->start);
	res->name[0] = '(';
	ft_strcat(res->name, nfa->name);
	ft_strcat(res->name, "+)");
	return (res);
}
