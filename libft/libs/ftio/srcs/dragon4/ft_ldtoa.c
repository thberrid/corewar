/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:44:53 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/04 19:53:41 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <limits.h>
#include "ftio/ft_types.h"
#include "ftio/ft_core.h"
#include "ftio/dragon.h"
#include "ftlib.h"

static long		get_fdig(long double d)
{
	long		r;

	r = 0;
	if (d < 0.0)
		d = -d;
	if (d == 0.0)
		return (0);
	if (d < 1.0)
		while (d < 1.0 && --r)
			d *= 10.0;
	else if (d >= 10.0)
		while (d >= 10.0 && ++r)
			d /= 10.0;
	return (r);
}

static int		dragon_prepare(t_float *fc, t_bint *num, t_bint *den)
{
	bi_set(den, 1);
	bi_set(num, fc->mantissa);
	if (fc->exponent > 0)
		bi_shift_left(num, fc->exponent);
	else
		bi_shift_left(den, -fc->exponent);
	return (0);
}

static size_t	dragon_end(int i, long fdig, char **res, size_t len)
{
	while (i - 1 < (fdig + 1))
	{
		len = add_digit(res, len, '0');
		i++;
	}
	if ((size_t)(fdig > 0 ? (fdig + 1) : 1) < len)
		(*res)[fdig > 0 ? (fdig + 1) : 1] = '.';
	else
		len = add_digit(res, len, '.');
	return (len);
}

static size_t	dragon4(char **res, const long fdig, t_float *fc)
{
	int			i;
	size_t		len;
	t_bint		num;
	t_bint		den;

	len = 0;
	i = dragon_prepare(fc, &num, &den);
	while (fdig < 0 && i++ <= -fdig)
		len = add_digit(res, len, '0');
	if (fdig > 0)
		bimul_pow10(&den, &den, fdig);
	else if (fdig < 0 && ((i = -(fdig - 1)) || 1))
		bimul_pow10(&num, &num, -fdig);
	while (bicmplng(&num, 0) > 0)
	{
		if (i != (fdig + 1))
		{
			len = add_digit(res, len, '0' + bidiv_maxq92(&num, &den));
			bimul10(&num, &num);
		}
		else
			len = add_digit(res, len, '0');
		++i;
	}
	return (dragon_end(i, fdig, res, len));
}

char			*ft_ldtoa(long double d)
{
	char		sign;
	char		*res;
	long		fdig;
	size_t		ln;
	t_float		fc;

	res = NULL;
	if (d != d)
		return (ft_strdup("nan"));
	if (d == (1.0 / 0.0) || d == -(1.0 / 0.0))
		return (ft_strdup(d < 0.0 ? "-inf" : "inf"));
	fc = get_float_components(d);
	fc.exponent -= (LDBL_MANT_DIG - 1);
	if ((sign = fc.sign))
		d = -d;
	fdig = get_fdig((long double)d);
	ln = dragon4(&res, fdig, &fc);
	if (res && res[(fdig = ft_idxof('.', res))] == '.' && !res[fdig + 1])
		ln = add_digit(&res, ln, '0');
	if (fc.sign)
	{
		add_digit(&res, ln, '-');
		((char *)ft_memmove(res + 1, res, ft_strlen(res + 1)))[-1] = '-';
	}
	return (res);
}
