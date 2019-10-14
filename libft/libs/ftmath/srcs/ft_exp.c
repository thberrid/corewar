/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 03:42:25 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/23 07:15:54 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include <inttypes.h>
#include <sys/cdefs.h>
#include "ftmath/fpmath.h"
#include "ftmath/ft_exp.h"

static const double	g_half[2] = {0.5, -0.5};
static const double	g_ln2hi[2] = {
	6.93147180369123816490e-01,
	-6.93147180369123816490e-01
};
static const double	g_ln2lo[2] = {
	1.90821492927058770002e-10,
	-1.90821492927058770002e-10
};

static double	compute(double x, double hi, double lo, int32_t k)
{
	double		twopk;
	double		t;
	double		y;
	double		c;

	t = x * x;
	if (k >= -1021)
		insert_word(&twopk, 0x3ff00000 + (k << 20), 0);
	else
		insert_word(&twopk, 0x3ff00000 + ((k + 1000) << 20), 0);
	c = x - t * (P1 + t * (P2 + t * (P3 + t * (P4 + t * P5))));
	if (k == 0)
		return (1.0 - ((x * c) / (c - 2.0) - x));
	y = 1.0 - ((lo - (x * c) / (2.0 - c)) - hi);
	if (k >= -1021)
	{
		if (k == 1024)
			return (y * 2.0 * 0x1p1023);
		return (y * twopk);
	}
	return (y * twopk * TWOM1000);
}

static double	get_components(double x, uint32_t hx, int32_t xsb)
{
	double		hi;
	double		lo;
	int32_t		k;

	k = 0;
	hi = 0.0;
	lo = 0.0;
	if (hx > 0x3fd62e42)
	{
		k = (int)(INVLN2 * x + g_half[xsb]);
		hi = x - ((double)k) * g_ln2hi[0];
		lo = ((double)k) * g_ln2lo[0];
		if (hx < 0x3FF0A2B2)
		{
			hi = x - g_ln2hi[xsb];
			lo = g_ln2lo[xsb];
			k = 1 - xsb - xsb;
		}
		x = (hi - lo);
	}
	else if (hx < 0x3e300000 && HUDGE2 + x > 1.0)
		return (1.0 + x);
	else if (hx >= 0x3e300000)
		k = 0;
	return (compute(x, hi, lo, k));
}

double			ft_exp(double x)
{
	uint32_t	hx;
	int32_t		xsb;

	hx = get_high_word(x);
	xsb = (hx >> 31) & 1;
	hx &= 0x7fffffff;
	if (hx >= 0x40862E42)
	{
		if (hx >= 0x7ff00000)
		{
			if (((hx & 0xfffff) | get_low_word(x)) != 0)
				return (x + x);
			return (xsb == 0) ? x : 0.0;
		}
		if (x > O_THRESHOLD)
			return (HUDGE2 * HUDGE2);
		if (x < U_THRESHOLD)
			return (TWOM1000 * TWOM1000);
	}
	return (get_components(x, hx, xsb));
}
