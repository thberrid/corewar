/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uoctal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 21:02:59 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 01:09:59 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "uoctal.h"
#include "ftio/ft_core.h"
#include "ftio/ft_types.h"
#include "ftlib.h"

static char			*uoctal(t_printf *const data, t_arg *const ar)
{
	unsigned int	v;
	char			*tab;
	int				ln;

	v = (unsigned int)ar->val.i;
	if ((ln = ft_unsignedlen_base(v, "01234567")) > ar->prec && (v || ar->prec))
		ar->prec = ln;
	if (flag(ar, F_ZERO) && ar->min > ar->prec)
		ar->prec = ar->min;
	if (flag(ar, F_HASH) && v != 0 && ar->prec <= ln)
		ar->prec++;
	if (!(tab = padded_ulltoa_octal(v, ar->prec, ar->min, flag(ar, F_MINS))))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{'H', TRUE, ARG_INT, short_short_uoctal},
	{'h', TRUE, ARG_INT, short_uoctal},
	{' ', TRUE, ARG_INT, uoctal},
	{'j', TRUE, ARG_INT, intmax_uoctal},
	{'l', TRUE, ARG_INT, long_uoctal},
	{'L', TRUE, ARG_INT, long_long_uoctal},
	{'q', TRUE, ARG_INT, quad_uoctal},
	{'z', TRUE, ARG_INT, size_uoctal},
	{'Z', TRUE, ARG_INT, ssize_uoctal},
	{'t', TRUE, ARG_INT, ptrdiff_uoctal},
	{'\0', FALSE, ARG_NON, NULL}
};

char				*convert_u_integer_octal(t_printf *data, t_arg *arg)
{
	int				i;
	int				prec;
	int				min;

	min = arg->min;
	prec = arg->prec;
	i = get_arg_a(data, arg->flag_idx, arg);
	i = (i || (arg->min_idx && get_arg_i(data, arg->min_idx, &min)));
	if (i || (arg->prec_idx && get_arg_i(data, arg->prec_idx, &prec)))
		return (NULL);
	i = 0;
	if (prec == 0 && flag(arg, F_HASH))
		prec = 1;
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

char				*convert_u_linteger_octal(t_printf *data, t_arg *arg)
{
	arg->conv.c = 'o';
	arg->length_modifier = ft_idxof('l', LEN_MD_CHRS);
	return (convert_u_integer_octal(data, arg));
}
