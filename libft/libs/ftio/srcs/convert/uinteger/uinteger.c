/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uinteger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:25:04 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 01:07:27 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "uinteger.h"
#include "ftio/ft_core.h"
#include "ftio/ft_types.h"
#include "ftlib.h"

static char			*uinteger(t_printf *const data, t_arg *const arg)
{
	unsigned int	v;
	char			*tab;

	v = (unsigned int)arg->val.i;
	if (flag(arg, F_ZERO))
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{'H', TRUE, ARG_INT, short_short_uinteger},
	{'h', TRUE, ARG_INT, short_uinteger},
	{' ', TRUE, ARG_INT, uinteger},
	{'j', TRUE, ARG_INT, intmax_uinteger},
	{'l', TRUE, ARG_INT, long_uinteger},
	{'L', TRUE, ARG_INT, long_long_uinteger},
	{'q', TRUE, ARG_INT, quad_uinteger},
	{'z', TRUE, ARG_INT, size_uinteger},
	{'Z', TRUE, ARG_INT, ssize_uinteger},
	{'t', TRUE, ARG_INT, ptrdiff_uinteger},
	{'\0', FALSE, ARG_NON, NULL}
};

char				*convert_u_integer(t_printf *data, t_arg *arg)
{
	int				i;
	int				min;
	int				prec;

	min = arg->min;
	prec = arg->prec;
	i = get_arg_a(data, arg->flag_idx, arg);
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

char				*convert_u_linteger(t_printf *data, t_arg *arg)
{
	arg->conv.c = 'u';
	arg->length_modifier = ft_idxof('l', LEN_MD_CHRS);
	return (convert_u_integer(data, arg));
}
