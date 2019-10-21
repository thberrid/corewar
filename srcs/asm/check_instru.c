/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instru.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:52:32 by smoreno-          #+#    #+#             */
/*   Updated: 2019/10/21 04:24:19 by thberrid         ###   ########.fr       */
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
			*line += i;
			return (1);
		}
		j++;
	}
	return (-1);
}

int		get_paramlen(int opcode)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (opcode == g_op_tab[i].id)
			return (g_op_tab[i].arg_cnt);
		i++;
	}
	return (-1);
}

void	free_split(char **params)
{
	int		i;

	i = 0;
	while (params[i])
	{
		ft_strdel(&(params[i]));
		i += 1;
	}
	ft_strdel(params);
}

int		ft_strnc(char *str, char c)
{
	int		sum;

	sum = 0;
	while (*str)
	{
		if (*str == c)
			sum += 1;
		str += 1;
	}
	return (sum);
}

int		is_paramtype_allowed(char param_type, t_instruct *inst, int i)
{
	if (param_type == IND_CODE)
		param_type = T_IND;
	if ((!(g_op_tab[(int)inst->id].args[i] ^ param_type)) < g_op_tab[(int)inst->id].args[i])
		return (1);
	return (0);
}

t_arg_type	get_ocp(char **param_raw, int param_len, t_instruct *inst)
{
	t_arg_type	ocp;
	int			i;
	int			j;
	char		param_type;

	i = 0;
	ocp = 0;
	while (param_raw[i])
	{
		j = 0;
		while (ft_isspace(param_raw[i][j]))
			j++;
		if (param_raw[i][j] == 'r')
			param_type = REG_CODE;
		else if (param_raw[i][0] == '%')
			param_type = DIR_CODE;
		else
			param_type = IND_CODE;
		if (!is_paramtype_allowed(param_type, inst, i))
			return (0);
		ocp += ((param_type << (param_len - i + 1) * 2));
		i++;
	}
	return (ocp);
}

int		ft_getparams(char *line, t_instruct *inst)
{
	char	**param_raw;
	int		param_len;

	param_len = get_paramlen(inst->id);
	if (param_len != 1 + ft_strnc(line, SEPARATOR_CHAR))
		return (-1);
	if (!(param_raw = ft_strsplit(line, SEPARATOR_CHAR)))
		return (-1);
	if (!(inst->ocp = get_ocp(param_raw, param_len, inst)))
		return (-1);
	if (!param_to_inst(param_raw, inst))
		return (-1);
	free_split(param_raw);
	return (1);
}

t_instruct	*add_inst(t_instruct_head *head)
{
	t_instruct	*new;

	if (!(new = ft_memalloc(sizeof(t_instruct))))
		return (NULL);
	new->next = head->head ? head->head : new;
	new->prev = head->head ? head->head->prev : new;
	if (head->slen == 0)
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

	/*
	ft_putstr(">> ");
	ft_bprint_fd(&(g_op_tab[1].args[1]), 1, 1);
	ft_putchar('\n');
	char tmp = g_op_tab[1].args[1] ^ 1;
	ft_putstr(">> ");
	ft_bprint_fd(&tmp, 1, 1);
	ft_putchar('\n');
*/

	i = 0;
	if (!(inst = add_inst(head)))
		return (-1);
	while (ft_isspace(*line))
		line++;
	if (ft_getlab(&line, inst) < 0)
			return (-1);
	if (ft_getopcode(&line, inst) < 0)
		return (-1);
	if (ft_getparams(line, inst) < 0)
		return (-1);
	return (1);
}
