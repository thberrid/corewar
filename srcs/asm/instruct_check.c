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

int			param_to_inst(char **param_raw, t_instruct *inst, char **line)
{
	int		i;
	int		j;
	int		len;
	char	is_reg;

	i = 0;
	while (param_raw[i])
	{
		j = 0;
		while (ft_isspace(param_raw[i][j]))
			j++;
		is_reg = param_raw[i][j] == 'r' ? 1 : 0;
		if (param_raw[i][j] == DIRECT_CHAR || param_raw[i][j] == 'r')
			j++;
		len = 0;
		while (param_raw[i][j + len] && !ft_isspace(param_raw[i][j + len]))
			len += 1;
		if (!len || (is_reg && len > 2))
			return (0);
		if (!(inst->params_str[i] = ft_strnew(len)))
			return (0);
		(*line) += push_str(inst->params_str[i], &(param_raw[i][j]), len, j);
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

int			get_this_param_ocp(char ocp, int i)
{
	int		code;

	code = 0;
	code += (ocp >> 2 * (3 - i)) & 2;
	code += (ocp >> (2 * (3 - i))) & 1;
	return (code);
}

int			update_progsize(t_instruct_head *head, t_instruct *inst)
{
	int		prog_size;
	int		i;
	char	code;

	inst->byt_index = head->length;
	if (!inst->id)
		return (0);
	prog_size = 1;
	if (g_op_tab[inst->id].ocp)
		prog_size += 1;
	i = 0;
	while (i < 3)
	{
		code = get_this_param_ocp(inst->ocp, i);
		if (code == 1)
			prog_size += 1;
		else if (code == 3)
			prog_size += 2;
		else if (code != 0)
			prog_size += (g_op_tab[inst->id].hdir ? 2 : 4);
		i++;
	}
	inst->len = prog_size;
	head->length += prog_size;
	return (0);
}

void		check_endline(char *line)
{
	while (line && *line)
	{
		if (*line == COMMENT_CHAR || *line == ';')
			ft_bzero(line, ft_strlen(line));
		line++;
	}
}

int			check_instruct(char *line, t_instruct_head *head)
{
	size_t		i;
	t_instruct	*inst;
	int			retrn;

	i = 1;
	check_endline(line);
	inst = head->head;
	if (inst)
		inst = inst->prev;
	if (!inst || inst->id || inst->label)
		inst = add_inst(head);
	if (!inst)
		return (-9);
	inst->line_n = head->line;
	while (ft_isspace(*line))
		line++;
	retrn = get_datas(line, head, inst, i);
	update_progsize(head, inst);
	return (retrn);
}
