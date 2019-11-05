/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 07:33:12 by smoreno-          #+#    #+#             */
/*   Updated: 2019/11/05 07:33:13 by smoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_deflab(t_instruct *inst, int *cflag, char *line, int len)
{
	char	*str;
	int	i;

	i = 0;
	while (i < len && ft_contains(line[i], LABEL_CHARS))
		i++;
	if (i == len)
	{
		if (!(inst->label = ft_strnew(len)))
			return (-9);
		ft_strncpy(inst->label, line, len);
	}
	else
	{
		if (!(str = ft_itoa(*cflag)))
			return (-9);
		if (!(inst->label = ft_strnew(8 + ft_strlen(str))))
				return (-9);
		ft_strcpy(inst->label, "defaut_n");
		ft_strcat(inst->label, str);
		(*cflag)++;
	}
	return (0);
}

int		debug_instruct(char *line, t_instruct_head *head)
{
	int 		i;
	int			i_param;
	int			len;
	t_instruct	*inst;
	int			param_len;
	char		param_type;

	inst = head->head;
	if (!inst)
		inst = add_inst(head);
	else
	{
		i = head->slen;
		inst = (inst->prev->label && !inst->prev->id) ? inst->prev : add_inst(head); 
	}
	if (!inst)
		return (-9);
	len = 0;
	while (ft_isspace(*line))
		line++;
	while (line[len] && line[len] != LABEL_CHAR && !ft_isspace(line[len]))
		len++;
	if (line[len] == LABEL_CHAR)
	{
		ft_deflab(inst, &(head->cflag), line, len);
		line += (len + 1);
	}
	while (ft_isspace(*line))
		line++;
	len = 0;
	while (line[len] && line[len] != DIRECT_CHAR && line[len] != LABEL_CHAR && !ft_isspace(line[len]))
		len++;
	i = 1;
	while (i <= 16)
	{
		if (!ft_strncmp(line, g_op_tab[i].name, len))
		{
			inst->id = i;
			param_len = get_paramlen(inst->id);
			line += len;
			i_param = 0;
			while (i_param < param_len)
			{
				len = 0;
				while (ft_isspace(*line))
					line++;
				while (line[len] && line[len] != SEPARATOR_CHAR && !ft_isspace(line[len]))
					len++;
				param_type = IND_CODE;
				if (*line == 'r')
					param_type = REG_CODE;
				if (*line == DIRECT_CHAR)
					param_type = DIR_CODE;
					ft_printf("%d\n", len);
				if (*line && is_paramtype_allowed(param_type, inst, i_param) && is_strn_valid(line, len))
				{
					if (!(inst->params_str[i_param] = ft_strnew(len)))
						return (-10);
					ft_strncpy(inst->params_str[i_param], line, len);
					inst->ocp += ((param_type << (3 - i) * 2));
				} 
				else
				{
					ft_printf("create new param\n");
				}
				line += len + 1;					
				i_param++;
			}
			break ;
		}
		i++;
	}
	return (0);
}