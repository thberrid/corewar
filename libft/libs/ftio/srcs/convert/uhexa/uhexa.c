/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uhexa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:26:04 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 01:09:20 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftio/ft_core.h"
#include "ftio/ft_types.h"
#include "ftlib.h"
#include "uhexa.h"

static char			*hexa(t_printf *const data, t_arg *const arg)
{
	unsigned int	v;
	int				len;
	char			*tab;

	v = (unsigned int)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "0123456789abcdef")) > arg->prec
		&& (v || arg->prec))
		arg->prec = len;
	if (flag(arg, F_HASH) && v != 0)
		arg->prec += 2;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa_hexa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'x';
	if (ft_isupper(arg->conv.c))
		ft_strupcase(tab);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{'H', TRUE, ARG_INT, short_short_hexa},
	{'h', TRUE, ARG_INT, short_hexa},
	{' ', TRUE, ARG_INT, hexa},
	{'j', TRUE, ARG_INT, intmax_hexa},
	{'l', TRUE, ARG_INT, long_hexa},
	{'L', TRUE, ARG_INT, long_long_hexa},
	{'q', TRUE, ARG_INT, quad_hexa},
	{'z', TRUE, ARG_INT, size_hexa},
	{'Z', TRUE, ARG_INT, ssize_hexa},
	{'t', TRUE, ARG_INT, ptrdiff_hexa},
	{'\0', FALSE, ARG_NON, NULL}
};

char				*convert_u_integer_hexa(t_printf *data, t_arg *arg)
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
