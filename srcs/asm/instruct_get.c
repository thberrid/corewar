/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 09:18:10 by thberrid          #+#    #+#             */
/*   Updated: 2019/11/08 09:41:59 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** ok go ask to the double-link-listed girl if you want really want to know
*/

t_instruct	*add_inst(t_instruct_head *head)
{
	t_instruct	*new;

	if (!(new = ft_memalloc(sizeof(t_instruct))))
		return (NULL);
	ft_bzero(new, sizeof(t_instruct));
	new->next = head->head ? head->head : new;
	new->prev = head->head ? head->head->prev : new;
	if (head->slen == 0)
		head->head = new;
	new->prev->next = new;
	new->next->prev = new;
	head->slen++;
	return (new);
}

t_instruct	*get_freeinst(t_instruct_head *head)
{
	t_instruct	*inst;
	t_instruct	*prev;

	inst = head->head;
	if (!inst)
		inst = add_inst(head);
	else
	{
		prev = inst->prev;
		inst = (prev->label && !prev->id) ? prev : add_inst(head);
	}
	if (!inst)
		return (NULL);
	return (inst);
}
