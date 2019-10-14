/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:46:28 by abaurens          #+#    #+#             */
/*   Updated: 2019/07/15 20:57:48 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftregex/nfa.h"
#include <stdlib.h>

t_nfa_st	*create_state(char is_end)
{
	t_nfa_st	*res;

	if (!(res = malloc(sizeof(t_nfa_st))))
		return (NULL);
	res->symbol = -1;
	res->type = NONE;
	res->is_end = is_end;
	res->transition_count = 0;
	res->transitions[0] = NULL;
	res->transitions[1] = NULL;
	return (res);
}

void		add_epsilon(t_nfa_st *from, t_nfa_st *to)
{
	from->type = EPSYLON;
	from->transitions[from->transition_count++] = to;
}

void		add_symbol(t_nfa_st *from, t_nfa_st *to, char symbol)
{
	from->type = SYMBOL;
	from->symbol = symbol;
	from->transitions[from->transition_count++] = to;
}
