/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nfa_union.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:11:36 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/25 10:21:18 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftregex/nfa.h"
#include "ftlib.h"
#include <stdlib.h>

/*
**	unify the two NFAs together. This match first OR second
**		This op manages the OR operator : [abc], (abc|def), etc
**
**		 /->fir_s=>fir_e-\
**	RES_S				  |->RES_E
**		 \->sec_s=>sec_e-/
*/

t_nfa	*nfa_union(t_nfa *first, t_nfa *second)
{
	t_nfa	*res;
	char	*n1;
	char	*n2;
	int		i;
	int		j;

	if (!(res = new_nfa()))
		return (NULL);
	n1 = first->name + (*first->name == '(');
	if ((i = ((*first->name == '(') && n1[(ft_idxof(')', n1) + 1)] == '(')))
		n1--;
	n2 = second->name + (*second->name == '(');
	if ((j = ((*second->name == '(') && n2[(ft_idxof(')', n2) + 1)] == '(')))
		n2--;
	add_epsilon(res->start, first->start);
	add_epsilon(res->start, second->start);
	add_epsilon(first->end, res->end);
	add_epsilon(second->end, res->end);
	second->end->is_end = 0;
	first->end->is_end = 0;
	res->name[0] = '(';
	ft_strncat(res->name, n1, ft_idxof(i ? 0 : ')', n1));
	ft_strcat(res->name, "|");
	ft_strncat(res->name, n2, ft_idxof(j ? 0 : ')', n2));
	return (res + !ft_strcat(res->name, ")"));
}
