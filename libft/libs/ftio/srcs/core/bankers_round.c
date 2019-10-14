/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bankers_round.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:44:18 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/02 16:56:00 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ftio/ft_core.h"
#include "ftlib.h"

char		*rnd_2(char *val, const size_t ln, const size_t blen)
{
	int		p;
	size_t	i;

	i = ln;
	while (i-- > 1)
	{
		if (val[i] == '.')
			continue;
		p = 1 + (val[i - 1] == '.');
		val[i - p] += (val[i] / blen);
		val[i] %= blen;
	}
	if ((size_t)(*val) == blen)
	{
		ft_memmove(val + 1, val, ln);
		*val = val[1] / blen;
		val[1] %= blen;
	}
	return (val);
}

char		*rnd(char *val, size_t ln, const size_t prec, const size_t blen)
{
	size_t	i;
	size_t	lim;
	char	*cur;
	char	next;
	char	f;

	f = 0;
	i = ln;
	lim = blen / 2;
	if (prec + 1 >= ln)
		return (val);
	while (--i > (prec + 1))
		f = (blen == 10 && (f || val[i]));
	i--;
	cur = val + (i - (val[i] == '.'));
	next = i + 1 > ln ? 0 : val[i + 1];
	f = (f || (i + 2 > ln ? 0 : val[i + 2]) % 2);
	if ((size_t)next > lim
		|| ((size_t)next == lim && (f || (blen == 10 && *cur % 2))))
		(*cur)++;
	return (rnd_2(val, ln, blen));
}

char		*banker_round(char *val, const size_t prec, const char *base)
{
	size_t	i;
	size_t	len;
	size_t	entl;
	size_t	blen;

	if (!val || !base)
		return (val);
	entl = ft_idxof('.', val);
	blen = ft_strlen(base);
	if (blen < 2 || !(len = ft_strlen(val)) || prec >= len || !val[entl])
		return (val);
	i = 0;
	while (i < len)
		if (i++ != entl)
			val[i - 1] = ft_idxof(val[i - 1], base);
	rnd(val, len, prec + entl, blen);
	i = 0;
	while (i < len)
		if ((size_t)(val[i++]) < blen)
			val[i - 1] = base[(int)val[i - 1]];
	return (val);
}

char		*round_tabflt(char *val, size_t prec, int *exp)
{
	size_t	point;
	char	sign;

	sign = 0;
	if (!ft_strchr(val, '.'))
		return (val);
	while (ft_contains(*val, " +-") && *(++val))
		sign++;
	banker_round(val, prec, DECI);
	if (exp && (point = ft_idxof('.', val)) != 1 && (*exp)++)
		*(((char *)ft_memmove(val + 2, val + 1, point - 1)) - 1) = '.';
	return (val - sign);
}

char		*round_hex(char *val, size_t prec, int *exp)
{
	char	sign;
	size_t	point;

	sign = 0;
	if (!val || !exp)
		return (val);
	while (ft_contains(*val, " +-") && *(++val))
		sign++;
	banker_round(val, prec, HEXA);
	if (exp && (point = ft_idxof('.', val)) != 1 && ((*exp) += 4))
		*(((char *)ft_memmove(val + 2, val + 1, point - 1)) - 1) = '.';
	return (val - sign);
}
