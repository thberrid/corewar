/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:16:59 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 01:10:38 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftio/ft_core.h"
#include "ftio/converter.h"
#include "ftio/ft_types.h"
#include "ftlib.h"

static char		*character(t_printf *data, t_arg *arg)
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

static char		*wide_char(t_printf *data, t_arg *arg)
{
	wchar_t		v[2];
	char		*res;
	int			len;
	int			tab_len;

	v[1] = 0;
	*v = (wchar_t)arg->val.i;
	len = ft_wchar_len(*v);
	if ((tab_len = arg->min) < len)
		tab_len = len;
	if (!(res = ft_memalloc(tab_len + 1)))
		return (NULL);
	ft_memset(res, flag(arg, F_ZERO) ? '0' : ' ', tab_len);
	len = tab_len - len;
	if (flag(arg, F_MINS))
		len = 0;
	ft_wstrtostr(res + len, v);
	insert_buffer(data, res, tab_len);
	free(res);
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, ARG_INT, character},
	{'l', TRUE, ARG_INT, wide_char},
	{'\0', FALSE, ARG_INT, NULL}
};

char			*convert_char(t_printf *data, t_arg *arg)
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

char			*convert_wchar(t_printf *data, t_arg *arg)
{
	arg->conv.c = 'c';
	arg->length_modifier = ft_idxof('l', LEN_MD_CHRS);
	return (convert_char(data, arg));
}
