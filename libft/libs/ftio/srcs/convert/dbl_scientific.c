/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_scientific.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:28:58 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 01:16:12 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "ftio/ft_types.h"
#include "ftio/ft_core.h"
#include "ftmath.h"
#include "ftlib.h"

char			*printf_ldbl_s(t_arg *const ar)
{
	size_t		add;
	size_t		l;
	char		*t;
	char		*r;
	char		s;

	if (!(t = exp_dbl(ar->val.lf, ar->prec)))
		return (NULL);
	if (ft_isupper(ar->conv.c))
		ft_strupcase(t);
	if ((s = (*t != '-' && flag(ar, (F_PLUS | F_SPAC)))) && !fnan(ar->val.lf))
		t = (char *)ft_freturn(t, (long)ft_strmcat(" ", t, -1));
	s = ((s || *t == '-') && !fnan(ar->val.lf));
	if (!flag(ar, F_HASH) && !ar->prec && ldbl_num(ar->val.lf))
		ft_memmove(t + s + 1, t + s + 2, ft_strlen(t + s + 1));
	l = ft_strlen(t);
	add = ((size_t)ar->min > l) ? ar->min - l : 0;
	if (!(r = ft_memalloc(l + add + 1)))
		return ((char *)ft_freturn(t, 0x0));
	if (*t == '-' || (*t == ' ' && ((flag(ar, F_PLUS) && (*t = '+')) || 1)))
		*r = *t;
	s *= flag(ar, F_ZERO);
	ft_memset(r + s, (flag(ar, F_ZERO)) ? '0' : ' ', add + l - s);
	ft_memcpy(r + add * !flag(ar, F_MINS) + s, t + s, l - s);
	return ((char *)ft_freturn(t, (long)r));
}

static char		*std_ldouble(t_printf *const data, t_arg *const arg)
{
	((void)data);
	if (!ldbl_num(arg->val.lf))
		arg->flags &= ~F_ZERO;
	return (printf_ldbl_s(arg));
}

static char		*std_double(t_printf *const data, t_arg *const arg)
{
	arg->val.lf = (long double)arg->val.f;
	if (!ldbl_num(arg->val.lf))
		arg->flags &= ~F_ZERO;
	return (std_ldouble(data, arg));
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, ARG_FLT, std_double},
	{'l', TRUE, ARG_FLT, std_double},
	{'L', TRUE, ARG_FLT, std_ldouble},
	{'\0', FALSE, ARG_NON, NULL}
};

char			*convert_double_scientific(t_printf *data, t_arg *arg)
{
	int			i;
	char		*res;
	int			min;
	int			prec;

	min = arg->min;
	prec = arg->prec;
	i = (arg->min_idx && get_arg_i(data, arg->min_idx, &min));
	i = (i || (arg->prec_idx && get_arg_i(data, arg->prec_idx, &prec)));
	if (i || get_arg_a(data, arg->flag_idx, arg))
		return (NULL);
	i = 0;
	if ((arg->min = min) < 0 && (arg->flags |= F_MINS))
		arg->min = -min;
	arg->prec = (prec < 0 ? 6 : prec);
	if (flag(arg, F_MINS))
		arg->flags &= ~F_ZERO;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	res = g_funcs[!!g_funcs[i].c * i].func(data, arg);
	ft_freturn(res, (long)insert_buffer(data, res, ft_idxof(0, res)));
	return (data->buf);
}
