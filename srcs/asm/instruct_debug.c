/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 07:33:12 by smoreno-          #+#    #+#             */
/*   Updated: 2019/11/10 06:22:31 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		get_available_type(t_instruct *inst, int param_n)
{
	int			i;
	char		param_type;

	param_type = 1;
	i = 0;
	while (i < 3)
	{
		if (is_paramtype_allowed(param_type, inst, param_n))
			return (param_type);
		i++;
		param_type *= 2;
	}
	return (1);
}

void		debug_ocp(t_instruct *inst, char **line, int par_n, int par_type)
{
	inst->ocp += ((par_type << (3 - par_n) * 2));
	inst->params_bits[par_n] = get_octet(inst->id, par_type);
	while (**line && **line != SEPARATOR_CHAR)
		(*line)++;
	if (**line == SEPARATOR_CHAR)
		(*line)++;
}

int			debug_params(char *line, t_instruct *inst)
{
	int		i_param;
	int		param_len;
	char	param_type;
	int		len;

	i_param = 0;
	param_len = get_paramlen(inst->id);
	while (i_param < param_len)
	{
		len = push_param(&line);
		param_type = push_paramtype(&line, &len);
		if (!(inst->params_str[i_param] = ft_strnew(len ? len : 1)))
			return (-9);
		if (*line && is_paramtype_allowed(param_type, inst, i_param)
			&& is_strn_valid(line, len))
			ft_strncpy(inst->params_str[i_param], line, len);
		else
			default_param(param_type, inst, i_param);
		line += len;
		debug_ocp(inst, &line, i_param, param_type);
		i_param++;
	}
	return (1);
}

int			debug_instruct(char *line, t_instruct_head *head)
{
	int			len;
	t_instruct	*inst;
	int			i;

	if (!(inst = get_freeinst(head)))
		return (-9);
	if ((len = push_label(&line, inst, &(head->cflag))) < -9)
		return (-9);
	i = 1;
	while (i <= 16)
	{
		if (!ft_strncmp(line, g_op_tab[i].name, len))
		{
			inst->id = i;
			if (debug_params(line += len, inst) < 0)
				return (-9);
			break ;
		}
		i++;
	}
	if (i == 17)
		default_op(inst);
	update_progsize(head, inst);
	return (0);
}
