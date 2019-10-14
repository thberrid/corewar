/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_postfix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 21:39:00 by abaurens          #+#    #+#             */
/*   Updated: 2019/07/15 20:41:45 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftregex/token.h"
#include "ftregex.h"
#include "ftlib.h"

static char	get_pair(char c)
{
	register char	*t;

	if ((t = ft_strchr(RE_SCP_OPN, c)) != NULL)
		return (RE_SCP_CLS[t - RE_SCP_OPN]);
	else if ((t = ft_strchr(RE_SCP_CLS, c)) != NULL)
		return (RE_SCP_OPN[t - RE_SCP_CLS]);
	return (0);
}

static void	handle_operators(t_toklst *new, t_toklst *stack, t_token *cur)
{
	if (stack->size && stack->head->type != SCOPE_OPN
		&& get_priority(stack->head->c) >= get_priority(cur->c))
		insert_after(new, pop_tok(stack, stack->head), NULL);
	insert_before(stack, cur, NULL);
}

static void	handle_scopes(t_toklst *new, t_toklst *stack, t_token *cur)
{
	while (stack->size && stack->head->type != SCOPE_OPN
		&& get_pair(cur->c) != stack->head->c)
		insert_after(new, pop_tok(stack, stack->head), NULL);
	free(pop_tok(stack, stack->head));
	free(cur);
}

void		to_postfix(t_toklst *lst)
{
	t_toklst	new;
	t_toklst	stack;
	t_token		*cur;

	cur = lst->head;
	ft_bzero(&new, sizeof(t_toklst));
	ft_bzero(&stack, sizeof(t_toklst));
	while (lst->size)
	{
		cur = pop_tok(lst, lst->head);
		if (is_operand(cur) || cur->type == QUANT)
			insert_after(&new, cur, NULL);
		else if (cur->type == SCOPE_OPN)
			insert_before(&stack, cur, NULL);
		else if (cur->type == OP)
			handle_operators(&new, &stack, cur);
		else if (cur->type == SCOPE_CLS)
			handle_scopes(&new, &stack, cur);
	}
	while (stack.size)
		insert_after(&new, pop_tok(&stack, stack.head), NULL);
	*lst = new;
}
