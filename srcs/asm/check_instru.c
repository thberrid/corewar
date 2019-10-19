/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instru.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:52:32 by smoreno-          #+#    #+#             */
/*   Updated: 2019/10/18 14:53:11 by smoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

extern t_op	g_op_tab[17];

int		ft_getlab(char **line, t_instruct *inst)
{
	int i;
	
	i = 0;
	while ((*line)[i] && (*line)[i] != LABEL_CHAR && !(ft_isspace((*line)[i])))
	{
		if (!ft_contains((*line)[i], LABEL_CHARS))
			return (-1);
		i++;
	}
	if ((*line)[i] == LABEL_CHAR)
	{
		if (!(inst->label = ft_strnew(i)))
			return (-1);
		inst->label = ft_strncpy(inst->label, *line, i);
		*line += i + 1;
	}
	return (0);
}

int		ft_getopcode(char **line, t_instruct *inst)
{
	int		i;
	int		j;

	i = 0;
	while (ft_isspace(**line))
		(*line)++;
	while ((*line)[i] && (*line)[i] != DIRECT_CHAR && !(ft_isspace((*line)[i])))
		i++;
	if (!i)
		return (-1);
	j = 0;
	while (g_op_tab[j].name)
	{
		if (!ft_strncmp(g_op_tab[j].name, *line, i))
		{
			inst->id = g_op_tab[j].id;
			ft_printf("id %d\n", inst->id);
			return (1);
		}
		j++;
	}
	return (-1);
}
/*
int		ft_getparams(char *line, t_instruct *inst)
{

	return (-1);
}
*/

t_instruct	*add_inst(t_instruct_head *head)
{
	t_instruct	*new;

	if (!(new = ft_memalloc(sizeof(t_instruct))))
		return (NULL);
	new->next = head->head ? head->head : new;
	new->prev = head->head ? head->head->prev : new;
	if (head->slen== 0)
		head->head= new;
	new->prev->next = new;
	new->next->prev = new;
	head->slen++;
	return (new);
}

int		check_instruct(char *line, t_instruct_head *head)
{
	int		i;
	t_instruct	*inst;

	i = 0;
	if (!(inst = add_inst(head)))
		return (-1);
	while (ft_isspace(*line))
		line++;
	if (ft_getlab(&line, inst) < 0)
			return (-1);
	if (ft_getopcode(&line, inst) < 0)
		return (-1);
	return (1);
}