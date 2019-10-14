/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:57:31 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/02 17:02:03 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio/ft_core.h"
#include "ftio/parser.h"
#include "ftlib.h"

static int		get_flags(const char *format, t_arg *arg)
{
	char		c;
	int			i;
	int			j;

	j = 0;
	i = -1;
	while ((c = FLAGS_V[++i]))
	{
		if (format[j] == c && (++j))
		{
			arg->flags |= g_flags_masks[i];
			i = -1;
		}
	}
	return (j);
}

int				get_min_width(const char *format, t_printf *data, t_arg *arg)
{
	int			i;
	const char	*f;

	i = 0;
	f = format;
	format += get_flags(format, arg);
	arg->min_idx = 0;
	if ((arg->min = 0) || *format == '*')
	{
		arg->min_idx = ++data->arg_count;
		if ((i = get_chain_format(format + 1, data, &arg->min_idx)) < 0)
			return (0);
		++i;
		return ((format + i) - f);
	}
	arg->min = ft_atoi(format);
	while (format[i] && format[i] >= '0' && format[i] <= '9')
		i++;
	return ((format + i) - f);
}

int				get_precision(const char *format, t_printf *data, t_arg *arg)
{
	int			i;
	const char	*f;

	i = 0;
	f = format;
	arg->prec = -1;
	arg->prec_idx = 0;
	if (*format++ != '.')
		return (0);
	if (*format == '*')
	{
		format += 1;
		arg->prec_idx = ++data->arg_count;
		if ((i = get_chain_format(format, data, &arg->prec_idx)) < 0)
			return (0);
		return ((format + i) - f);
	}
	while (format[i] && format[i] >= '0' && format[i] <= '9')
		i++;
	arg->prec = ft_atoi(format);
	return ((format + i) - f);
}

int				get_length_modifier(const char *frm, t_printf *data, t_arg *arg)
{
	char		c;
	int			i;
	int			j;

	j = 0;
	i = -1;
	c = *frm;
	(void)data;
	arg->length_modifier = -1;
	if (ft_contains(frm[j], LEN_MD) == 1)
		arg->length_modifier = ft_idxof(frm[j++], LEN_MD);
	arg->length_modifier++;
	if (frm[j] == c)
	{
		if (c != 'l' && c != 'h')
			return (j);
		arg->length_modifier++;
		j++;
	}
	while ((c = LEN_MD[++i]))
		if (frm[j] == c && (++j))
			i = -1;
	return (j);
}

int				get_chain_format(const char *format, t_printf *data, size_t *v)
{
	int			i;

	i = 0;
	while (format[i] && (format[i] >= '0' && format[i] <= '9'))
		i++;
	if (i <= 0)
	{
		if (format[i] == '$' || data->use_chain_format == TRUE)
			return (-1);
		data->use_chain_format = FALSE;
		return (i);
	}
	if (format[i] != '$' && data->use_chain_format == MAYBE)
	{
		data->use_chain_format = FALSE;
		return (-1);
	}
	if (format[i] != '$' || data->use_chain_format == FALSE)
		return (-1);
	data->use_chain_format = TRUE;
	*v = ft_atoi(format);
	return (i + 1);
}
