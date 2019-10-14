/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:17:28 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 01:08:47 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "length.h"
#include "ftio/ft_core.h"
#include "ftio/ft_types.h"

static char		*length(t_printf *const data, t_arg *const arg)
{
	int			*v;

	v = (int *)arg->val.p;
	*v = data->len;
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{'H', TRUE, ARG_INT, short_short_length},
	{'h', TRUE, ARG_INT, short_length},
	{' ', TRUE, ARG_INT, length},
	{'j', TRUE, ARG_INT, intmax_length},
	{'l', TRUE, ARG_INT, long_length},
	{'L', TRUE, ARG_INT, long_long_length},
	{'q', TRUE, ARG_INT, quad_length},
	{'z', TRUE, ARG_INT, size_length},
	{'Z', TRUE, ARG_INT, ssize_length},
	{'t', TRUE, ARG_INT, ptrdiff_length},
	{'\0', FALSE, ARG_NON, NULL}
};

char			*convert_length(t_printf *data, t_arg *arg)
{
	int			i;

	i = 0;
	if (get_arg_a(data, arg->flag_idx, arg))
		return (NULL);
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}
