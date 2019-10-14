/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:45:42 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 01:14:27 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftio/converter.h"
#include "ftio/ft_types.h"
#include "ftio/ft_core.h"
#include "ftlib.h"

static char		*padd(char *res, t_arg *arg)
{
	int			from;
	size_t		add;
	size_t		len;

	add = 0;
	from = 0;
	if ((len = ft_strlen(res)) < (size_t)arg->min)
		add = arg->min - len;
	if (flag(arg, F_MINS))
		from = len;
	else
		ft_memmove(res + add, res, len);
	ft_memset(res + from, flag(arg, F_ZERO) ? '0' : ' ', add);
	return (res);
}

static char		*wide_string(t_printf *data, t_arg *arg)
{
	wchar_t		*v;
	char		*res;
	int			len;
	int			tab_len;

	if (!(v = (wchar_t *)arg->val.p))
		v = L"(null)";
	if ((len = ft_wstrlen(v)) > arg->prec && arg->prec >= 0)
		len = arg->prec;
	if ((tab_len = arg->min) < len)
		tab_len = len;
	if (!(res = ft_memalloc(tab_len + 1)))
		return (NULL);
	ft_memset(res, flag(arg, F_ZERO) ? '0' : ' ', len);
	tab_len -= (flag(arg, F_MINS) ? tab_len : len);
	ft_wstrtostr(res, v);
	padd(res, arg);
	insert_buffer(data, res, ft_strlen(res));
	free(res);
	return (data->buf);
}

static char		*character_string(t_printf *data, t_arg *arg)
{
	char		*v;
	char		*res;
	int			len;
	int			tab_len;

	if (!(v = (char *)arg->val.p))
		v = "(null)";
	if ((len = ft_strlen(v)) > arg->prec && arg->prec >= 0)
		len = arg->prec;
	if ((tab_len = arg->min) < len)
		tab_len = len;
	if (!(res = ft_memalloc(tab_len + 1)))
		return (NULL);
	res[tab_len] = 0;
	ft_memset(res, flag(arg, F_ZERO) ? '0' : ' ', tab_len);
	tab_len -= (flag(arg, F_MINS) ? tab_len : len);
	ft_strncpy(res + tab_len, v, len);
	insert_buffer(data, res, ft_strlen(res));
	free(res);
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, ARG_PTR, character_string},
	{'l', TRUE, ARG_PTR, wide_string},
	{'\0', FALSE, ARG_NON, NULL}
};

char			*convert_string(t_printf *data, t_arg *arg)
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
	arg->prec = prec;
	if ((arg->min = min) < 0 && (arg->flags |= F_MINS))
		arg->min = -min;
	if (flag(arg, F_MINS))
		arg->flags &= ~F_ZERO;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}

char			*convert_wstring(t_printf *data, t_arg *arg)
{
	arg->conv.c = 's';
	arg->length_modifier = ft_idxof('l', LEN_MD_CHRS);
	return (convert_string(data, arg));
}
