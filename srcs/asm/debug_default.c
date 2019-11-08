/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 06:01:11 by thberrid          #+#    #+#             */
/*   Updated: 2019/11/08 09:12:11 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_deflab(t_instruct *inst, int *cflag, char *line, int len)
{
	char	*str;
	int		i;

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

int			default_op(t_instruct *inst)
{
	inst->id = 1;
	inst->ocp = -128;
	if (!(inst->params_str[0] = ft_strnew(1)))
		return (-9);
	inst->params_str[0][0] = '1';
	inst->params_bits[0] = 4;
	return (1);
}

void		default_param(int param_type, t_instruct *inst, int i_param)
{
	param_type = get_available_type(inst, i_param);
	if (param_type == T_IND)
		param_type = IND_CODE;
	inst->params_str[i_param][0] = '1';
}
