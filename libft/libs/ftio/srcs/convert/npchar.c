/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npchar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:44:41 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/02 16:35:47 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftio/ft_types.h"
#include "ftio/ft_core.h"
#include "ftmath.h"
#include "ftlib.h"

static char		*printable(t_printf *data, t_arg *arg)
{
	char		v[2];
	char		*res;
	int			tab_len;

	v[1] = 0;
	*v = (char)arg->val.i;
	if (arg->min < 1)
		arg->min = 1;
	tab_len = arg->min;
	if (!(res = ft_memalloc(tab_len + 1)))
		return (NULL);
	res[tab_len] = 0;
	ft_memset(res, flag(arg, F_ZERO) ? '0' : ' ', tab_len);
	tab_len -= (flag(arg, F_MINS) ? tab_len : 1);
	ft_strncpy(res + tab_len, v, 1);
	return ((char *)ft_freturn(res, (long)insert_buffer(data, res, arg->min)));
}

static char		*non_printable(t_printf *data, t_arg *arg)
{
	int			len;
	char		v[6];
	char		*res;
	int			tab_len;

	if (ft_isprint((char)arg->val.i))
		return (printable(data, arg));
	len = chtoa_base(v, (char)arg->val.i, flag(arg, F_HASH) ? DECI : HEXA);
	if ((tab_len = arg->min) < len)
		tab_len = len;
	if (!(res = ft_memalloc(tab_len + 1)))
		return (NULL);
	res[tab_len] = 0;
	ft_memset(res, flag(arg, F_ZERO) ? '0' : ' ', tab_len);
	tab_len -= (flag(arg, F_MINS) ? tab_len : len);
	ft_strncpy(res + tab_len, v, len);
	len += tab_len;
	return ((char *)ft_freturn(res, (long)insert_buffer(data, res, len)));
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, ARG_PTR, non_printable},
	{'\0', FALSE, ARG_NON, NULL}
};

char			*convert_non_printable_char(t_printf *data, t_arg *arg)
{
	int			i;
	int			prec;
	int			min;

	min = arg->min;
	prec = arg->prec;
	i = get_arg_a(data, arg->flag_idx, arg);
	i = (i || (arg->min_idx && get_arg_i(data, arg->min_idx, &min)));
	if (i || (arg->prec_idx && get_arg_i(data, arg->prec_idx, &prec)))
		return (NULL);
	i = 0;
	if ((arg->min = min) < 0 && (arg->flags |= F_MINS))
		arg->min = -min;
	if (flag(arg, F_MINS))
		arg->flags &= ~F_ZERO;
	arg->prec = (prec < 0 ? 1 : prec);
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}
