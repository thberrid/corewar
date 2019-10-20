/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 05:10:47 by thberrid          #+#    #+#             */
/*   Updated: 2019/10/20 02:42:12 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	instruct_free(t_instruct_head *head)
{
	size_t		i;
	t_instruct	*tmp;
	t_instruct	*next;

	i = 0;
	tmp = head->head;
	while (i < head->slen)
	{
		next = tmp->next;
		ft_memdel((void **)&(tmp->label));
		ft_memdel((void **)&tmp);
		tmp = next;
		i++;
	}
}
