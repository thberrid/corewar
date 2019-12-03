/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 05:10:47 by thberrid          #+#    #+#             */
/*   Updated: 2019/11/08 09:13:46 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** ok lol kevin has got a problem with the leaks and valgrind and stuff
*/

void	free_split(char **params)
{
	int		i;

	i = 0;
	while (params[i])
	{
		free(params[i]);
		i += 1;
	}
	free(params);
}

int		instruct_free(t_instruct_head *head)
{
	size_t		i;
	int			j;
	int			param_len;
	t_instruct	*tmp;
	t_instruct	*next;

	i = 0;
	tmp = head->head;
	while (i < head->slen)
	{
		next = tmp->next;
		ft_memdel((void **)&(tmp->label));
		j = 0;
		param_len = get_paramlen(tmp->id);
		while (j < param_len)
		{
			ft_memdel((void **)&(tmp->params_str[j]));
			j += 1;
		}
		ft_memdel((void **)&tmp);
		tmp = next;
		i++;
	}
	return (0);
}
