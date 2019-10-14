/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floating_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:39:57 by abaurens          #+#    #+#             */
/*   Updated: 2019/07/04 02:32:46 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include <stdlib.h>
#include "ftio/ft_core.h"
#include "ftio/ft_types.h"
#include "ftmath.h"
#include "ftlib.h"

t_float				get_float_components(long double d)
{
	t_float			ret;
	t_float_conv	conv;
	int				exp_ln;
	int				man_ln;

	exp_ln = 0;
	ft_bzero(&conv, sizeof(conv));
	conv.value = d;
	man_ln = LDBL_MAX_EXP;
	while (man_ln != 0 && ++exp_ln)
		man_ln >>= 1;
	man_ln = LDBL_MANT_DIG - (sizeof(d) == sizeof(double));
	ft_memcpy(&ret.mantissa, conv.bytes, man_ln / 8);
	ret.exponent = *((unsigned short *)(conv.bytes + (man_ln / 8)));
	ret.sign = ret.exponent >> exp_ln;
	ret.exponent &= ~(1 << exp_ln);
	if (d != 0.0 && d != -0.0)
		ret.exponent -= (LDBL_MAX_EXP - 1);
	return (ret);
}

long double			dbl_abs(long double *d, char *sign)
{
	char			s;

	if (d && (s = get_float_components(*d).sign))
		*d = -*d;
	if (d && sign)
		*sign = s;
	return (d ? *d : 0.0 / 0.0);
}

char				ldbl_num(long double d)
{
	return (!fnan(d) && dbl_abs(&d, NULL) != (1.0 / 0.0));
}
