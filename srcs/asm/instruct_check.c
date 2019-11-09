/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <smoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:52:32 by smoreno-          #+#    #+#             */
/*   Updated: 2019/11/08 09:18:53 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** take an ocp (REG_CODE / DIR_CODE / IND_CODE)
** and look in g_op_tab.args
** en utilisant les bitwise operator
** par exemple : par exemple pour `ld` on a {T_DIR | T_IND, T_REG}
** ce qui donne {2 | 4, 1}, en binaire {0010 | 0100, 0001}
** et du coup le | il superpose tout c'est trop pratique et
** COMME PAR HASARD OUPS aucun bit ne se superpose
** ca donne {0110 | 0001} et du coup on peut regarder facilement
*/

int			is_paramtype_allowed(char param_type, t_instruct *inst, int i)
{
	if (param_type == IND_CODE)
		param_type = T_IND;
	if ((g_op_tab[inst->id].args[i] ^ param_type) < g_op_tab[inst->id].args[i])
		return (1);
	return (0);
}

int			param_to_inst(char **param_raw, t_instruct *inst, char **line)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (param_raw[i])
	{
		j = 0;
		while (ft_isspace(param_raw[i][j]))
			j++;
		if (param_raw[i][j] == DIRECT_CHAR || param_raw[i][j] == 'r')
			j++;
		len = 0;
		while (param_raw[i][j + len] && !ft_isspace(param_raw[i][j + len]))
			len += 1;
		if (!len)
			return (0);
		if (!(inst->params_str[i] = ft_strnew(len)))
			return (0);
		ft_bzero(inst->params_str[i], len);
		ft_strncpy(inst->params_str[i], &(param_raw[i][j]), len);
		(*line) += (j + 1);
		i += 1;
	}
	return (1);
}

/*
** ok the idea is
** le op code is 1 octet
** + 1 octet for the ocp, but he is optionnal so you have to check
** + 1, 2 or 4 for each argument soooooo you have to check each one
** with bitwise again
** et voila
*/

int			update_progsize(t_instruct_head *head, t_instruct *inst)
{
	int		prog_size;
	int		i;
	char	code;

	prog_size = 1;
	if (g_op_tab[inst->id].ocp)
		prog_size += 1;
	i = 0;
	while (i < 3)
	{
		code = 0;
		code += (inst->ocp >> 2 * (3 - i)) & 2;
		code += (inst->ocp >> (2 * (3 - i))) & 1;
		if (code == 1)
			prog_size += 1;
		else if (code == 3)
			prog_size += 2;
		else if (code != 0)
			prog_size += (g_op_tab[inst->id].hdir ? 2 : 4);
		i++;
	}
	inst->len = prog_size;
	inst->byt_index = head->length;
	head->length += prog_size;
	return (0);
}

void		check_endline(char *line)
{
	while (line && *line)
	{
		if (*line == COMMENT_CHAR)
			ft_bzero(line, ft_strlen(line));
		line++;
	}
}

int			check_instruct(char *line, t_instruct_head *head)
{
	size_t		i;
	t_instruct	*inst;
	t_instruct	*prev;

	i = 1;
	check_endline(line);
	inst = head->head;
	if (!inst)
		inst = add_inst(head);
	else
	{
		i = head->slen;
		prev = inst->prev;
		inst = (!prev->id) ? prev : add_inst(head);
	}
	if (!inst)
		return (-9);
	inst->line_n = head->line;
	while (ft_isspace(*line))
		line++;
	return (get_datas(line, head, inst, i));
}
