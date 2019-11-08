/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 07:04:22 by thberrid          #+#    #+#             */
/*   Updated: 2019/11/08 07:10:40 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			get_octet(t_byte id, char param_type)
{
	if (param_type == REG_CODE)
		return (1);
	if (param_type == IND_CODE)
		return (2);
	if (param_type == DIR_CODE && g_op_tab[id].hdir)
		return (2);
	return (4);
}

int			ft_getlab(char **line, t_instruct *inst)
{
	int i;

	i = 0;
	while ((*line)[i] && (*line)[i] != LABEL_CHAR && !(ft_isspace((*line)[i])))
	{
		if ((*line)[i] == DIRECT_CHAR)
			return (0);
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

/*
** take the name of an instruction and
** return the op_code
*/

int			ft_getopcode(char **line, t_instruct *inst)
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
			*line += i;
			return (1);
		}
		j++;
	}
	return (-1);
}

int			get_datas(char *s, t_instruct_head *hd, t_instruct *inst, size_t i)
{
	if (i <= hd->slen && ft_getlab(&s, inst) < 0)
		return (-1);
	while (ft_isspace(*s))
		s++;
	if (!*s)
		return (1);
	if (ft_getopcode(&s, inst) < 0)
		return (-5);
	if (ft_getparams(&s, inst) < 0)
		return (-3);
	update_progsize(hd, inst);
	return (1);
}
