/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp80math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 06:00:15 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/23 06:59:37 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath/fpmath.h"

t_ieeel2bits	ld80c(uint64_t m, uint16_t ex, long double v)
{
	t_ieeel2bits	res;

	res.xbits.man = m;
	res.xbits.expsign = (0x3fff + (ex)) | (v < 0 ? 0x8000 : 0);
	return (res);
}

void			set_ldbl_expsign(long double *x, uint16_t exp)
{
	t_ieeel2bits	converter;

	converter.e = *x;
	converter.xbits.expsign = exp;
	*x = converter.e;
}

void			extract_ldbl80_word(long double x, uint16_t *exp, uint64_t *man)
{
	t_ieeel2bits	converter;

	converter.e = x;
	*exp = converter.xbits.expsign;
	*man = converter.xbits.man;
}
