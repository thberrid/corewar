/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_automaton.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 09:46:51 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/16 16:33:24 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftregex/t_token.h"
#include "ftregex/token.h"
#include "ftregex/nfa.h"
#include "ftlib.h"
#include "ftio.h"

static void	print_clear_nfa(t_nfstk *stack)
{
	t_nfa	*nfa;

	ft_printf("nfas:\n");
	while (stack->size)
	{
		nfa = pop_nfa(stack);
		ft_printf("  {%s}\n", nfa->name);
		free(nfa->end);
		free(nfa->start);
		free(nfa);
	}
}

static void	handle_ops(t_nfstk *stack, char op)
{
	t_nfa		*a;
	t_nfa		*b;
	t_nfa		*res;
	const char	*ops = "|+";
	t_nfa		*(*const funcs[2])(t_nfa *first, t_nfa *second) = {
		nfa_union, nfa_concat
	};

	res = NULL;
	b = pop_nfa(stack);
	a = pop_nfa(stack);
	ft_printf("opperator  : {%s} %c {%s}\n", a->name, op, b->name);
	res = funcs[ft_idxof(op, ops)](a, b);
	free(a);
	free(b);
	push_nfa(stack, res);
}

static void	handle_quantifiers(t_nfstk *stack, char quantifier)
{
	t_nfa		*a;
	t_nfa		*res;
	const char	*ops = "+*";
	t_nfa		*(*const funcs[2])(t_nfa *nfa) = {
		nfa_once, nfa_closure
	};

	a = pop_nfa(stack);
	ft_printf("quantifier : {%s}%c\n", a->name, quantifier);
	res = funcs[ft_idxof(quantifier, ops)](a);
	free(a);
	push_nfa(stack, res);
}

void		*to_nfa(t_toklst *lst)
{
	t_token	*cur;
	t_nfstk	stack;

	ft_bzero(&stack, sizeof(t_nfstk));
	while (lst->size)
	{
		cur = pop_tok(lst, lst->head);
		if (cur->type == OP)
			handle_ops(&stack, cur->c);
		else if (cur->type == QUANT)
			handle_quantifiers(&stack, cur->c);
		else
			push_nfa(&stack, from_symbol(cur->c));
		ft_memdel(&cur);
	}
	print_clear_nfa(&stack);
	return (NULL);
}
