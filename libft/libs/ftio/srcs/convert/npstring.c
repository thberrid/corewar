/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npstring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:44:41 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 08:04:58 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftio/ft_types.h"
#include "ftio/ft_core.h"
#include "ftmath.h"
#include "ftlib.h"

static size_t	ft_unprint_strlen(register const char *s, const char *base)
{
	register size_t	len;

	len = 0;
	(void)base;
	while (s && *s)
	{
		if (!ft_isprint(*s))
			len += chtoa_base(NULL, *s, base);
		else
			len++;
		s++;
	}
	return (len);
}

static char		*ft_unprint_strncpy(char *dest, char *src, size_t n, char *b)
{
	register char	*d;
	register char	*s;

	d = dest;
	s = src;
	if (n <= 0 || !dest || !src)
		return (dest);
	while (*s)
	{
		if (!ft_isprint(*d = *s))
			d += chtoa_base(d, *d, b);
		else
			d++;
		s++;
	}
	return (dest);
}

static char		*non_printable(t_printf *data, t_arg *arg)
{
	char		*v;
	char		*res;
	char		*base;
	int			len;
	int			tab_len;

	base = flag(arg, F_HASH) ? DECI : HEXA;
	v = (!arg->val.p) ? "(null)" : (char *)arg->val.p;
	if ((len = ft_unprint_strlen(v, base)) > arg->prec && arg->prec >= 0)
		len = arg->prec;
	if ((tab_len = arg->min) < len)
		tab_len = len;
	if (!(res = malloc(tab_len + 1)))
		return (NULL);
	res[tab_len] = 0;
	ft_memset(res, flag(arg, F_ZERO) ? '0' : ' ', tab_len);
	tab_len -= (flag(arg, F_MINS) ? tab_len : len);
	ft_unprint_strncpy(res + tab_len, v, len, base);
	insert_buffer(data, res, ft_strlen(res));
	free(res);
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, ARG_PTR, non_printable},
	{'\0', FALSE, ARG_NON, NULL}
};

char			*convert_non_printable_string(t_printf *data, t_arg *arg)
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
	arg->prec = prec;
	if (flag(arg, F_MINS))
		arg->flags &= ~F_ZERO;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}
