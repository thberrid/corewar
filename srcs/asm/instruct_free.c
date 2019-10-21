/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 05:10:47 by thberrid          #+#    #+#             */
/*   Updated: 2019/10/21 05:48:31 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	instruct_free(t_instruct_head *head)
{
	size_t		i;
	int			j;
	t_instruct	*tmp;
	t_instruct	*next;

	i = 0;
	tmp = head->head;
	while (i < head->slen)
	{
		next = tmp->next;
		ft_memdel((void **)&(tmp->label));
		j = 0;
		while (tmp->params_str[j])
		{
			ft_memdel((void **)&(tmp->params_str[j]));
			j += 1;
		}
		ft_memdel((void **)&tmp);
		tmp = next;
		i++;
	}
}
