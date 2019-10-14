/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nfa_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:45:46 by abaurens          #+#    #+#             */
/*   Updated: 2019/07/15 20:50:51 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftregex/nfa.h"

void	push_nfa(t_nfstk *stack, t_nfa *nfa)
{
	nfa->next = stack->head;
	stack->head = nfa;
	++stack->size;
}

t_nfa	*pop_nfa(t_nfstk *stack)
{
	t_nfa	*res;

	if (!(res = stack->head))
		return (NULL);
	stack->head = res->next;
	res->next = NULL;
	--stack->size;
	return (res);
}
