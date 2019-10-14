/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_compact.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:29:42 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 01:13:52 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio/converter.h"
#include "ftio/ft_types.h"
#include "ftio/ft_core.h"
#include "ftmath.h"
#include "ftlib.h"
#include "ftio.h"

static char		*padd(char *str, t_arg *arg)
{
	long double	v;
	size_t		add;
	size_t		len;
	char		*res;
	char		sign;

	sign = 0;
	if (!str)
		return (str);
	v = arg->val.lf;
	len = ft_strlen(str);
	if (flag(arg, F_ZERO) && ft_contains(*str, " +-") && (sign = *str))
		str++;
	add = ((size_t)arg->min > len ? arg->min - len : 0);
	if (!(res = ft_memalloc(len + add + 1)))
		return ((char *)ft_freturn(str, 0x0));
	ft_memset(res, flag(arg, F_ZERO) && ldbl_num(v) ? '0' : ' ', len + add);
	add *= !flag(arg, F_MINS);
	ft_memmove(res + add + !!sign, str, ft_strlen(str));
	if (sign && --str)
		*res = sign;
	return ((char *)ft_freturn(str, (long)res));
}

static char		*remove_zeros(char *str, t_arg *arg)
{
	size_t		i;
	size_t		len;
	char		type;

	if (!str || !ft_strchr(str, '.'))
		return (str);
	len = ft_min(ft_idxof('e', str), ft_idxof('E', str));
	type = (str[len] == 'e' || str[len] == 'E');
	i = len - 1;
	if (!flag(arg, F_HASH))
		while (str[i] == '0' && (str[i - 1] != '.' || !flag(arg, F_HASH)))
			str[i--] = type ? '0' : 0;
	if (!flag(arg, F_HASH) && str[i] == '.' && (i-- || 1))
		str[i + 1] = type ? str[i + 1] : 0;
	if (type)
		ft_memmove(str + i + 1, str + len, ft_strlen(str + len - 1));
	return (str);
}

static char		*long_double(t_printf *const data, t_arg *const ar)
{
	long double	tmp;
	int			exp;
	char		*res;
	int			min;
	char		n;

	min = ar->min;
	ar->min = 0;
	tmp = ar->val.lf;
	ar->prec += !ar->prec;
	if ((n = (!fnan(tmp))))
		dbl_abs(&tmp, NULL);
	ar->prec--;
	if (!(res = printf_ldbl_s(ar)))
		return (NULL);
	ar->prec++;
	exp = ldbl_num(ar->val.lf) ? ft_atoi(res + ft_idxof('e', res) + 1) : 0;
	if (!(n && (exp < -4 || exp >= ar->prec)) && ((ar->prec -= (exp + 1)) || 1))
		res = (char *)ft_freturn(res, (long)printf_ldbl(data, ar));
	ar->min = min;
	res = padd(remove_zeros(res, ar), ar);
	exp = ft_strlen(res);
	return ((char *)ft_freturn(res, (long)insert_buffer(data, res, exp)));
}

static char		*std_double(t_printf *const data, t_arg *const arg)
{
	arg->val.lf = (long double)arg->val.f;
	return (long_double(data, arg));
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, ARG_FLT, std_double},
	{'l', TRUE, ARG_FLT, std_double},
	{'L', TRUE, ARG_FLT, long_double},
	{'\0', FALSE, ARG_NON, NULL}
};

char			*convert_double_compact(t_printf *data, t_arg *arg)
{
	int			i;
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
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}
