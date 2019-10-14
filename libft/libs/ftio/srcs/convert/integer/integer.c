/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:20:02 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 01:10:13 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "integer.h"
#include "ftio/ft_core.h"
#include "ftio/ft_types.h"
#include "ftlib.h"

static char	*integer(t_printf *const data, t_arg *const ar)
{
	int		v;
	size_t	l;
	char	*tab;

	v = (int)ar->val.i;
	if ((long)(l = (ft_numlen(v) - (v < 0))) > ar->prec && (v || ar->prec))
		ar->prec = l;
	if (flag(ar, (F_PLUS | F_SPAC)) && v >= 0 && ++l)
		ar->prec++;
	if ((v != 0 || ar->prec != 0) && (l + (v < 0)) > (size_t)ar->min)
		ar->min = l + (v < 0);
	if (flag(ar, F_ZERO) && ar->prec < ar->min)
		ar->prec = ar->min - (v < 0);
	if (!(tab = padded_lltoa(v, ar->prec, ar->min, flag(ar, F_MINS))))
		return (NULL);
	if (flag(ar, (F_PLUS | F_SPAC)) && (int)ar->val.i >= 0)
		tab[ft_idxof('0', tab)] = flag(ar, F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{'H', TRUE, ARG_INT, short_short_integer},
	{'h', TRUE, ARG_INT, short_integer},
	{' ', TRUE, ARG_INT, integer},
	{'j', TRUE, ARG_INT, intmax_integer},
	{'l', TRUE, ARG_INT, long_integer},
	{'L', TRUE, ARG_INT, long_long_integer},
	{'q', TRUE, ARG_INT, quad_integer},
	{'z', TRUE, ARG_INT, size_integer},
	{'Z', TRUE, ARG_INT, ssize_integer},
	{'t', TRUE, ARG_INT, ptrdiff_integer},
	{'\0', FALSE, ARG_INT, NULL}
};

char		*convert_integer(t_printf *const data, t_arg *const arg)
{
	int		i;
	int		prec;
	int		min;

	min = arg->min;
	prec = arg->prec;
	i = (get_arg_a(data, arg->flag_idx, arg));
	i = (i || (arg->min_idx && get_arg_i(data, arg->min_idx, &min)));
	if (i || (arg->prec_idx && get_arg_i(data, arg->prec_idx, &prec)))
		return (NULL);
	i = 0;
	arg->prec = prec;
	if ((arg->min = min) < 0 && (arg->flags |= F_MINS))
		arg->min = -min;
	if (prec >= 0 || flag(arg, F_MINS))
		arg->flags &= ~F_ZERO;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}

char		*convert_linteger(t_printf *const data, t_arg *const arg)
{
	arg->conv.c = 'd';
	arg->length_modifier = ft_idxof('l', LEN_MD_CHRS);
	return (convert_integer(data, arg));
}
