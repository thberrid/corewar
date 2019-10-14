/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 06:17:12 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/23 07:20:13 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include <inttypes.h>
#include <sys/cdefs.h>
#include "ftmath/fpmath.h"
#include "ftmath/ft_expf.h"

static const float	g_half[2] = {0.5, -0.5};
static const float	g_ln2hi[2] = { 6.9314575195e-01, -6.9314575195e-01};
static const float	g_ln2lo[2] = {1.4286067653e-06, -1.4286067653e-06};

static double	compute(double x, double hi, double lo, int32_t k)
{
	double		twopk;
	double		t;
	double		y;
	double		c;

	t = x * x;
	if (k >= -125)
		twopk = set_float_word(0x3f800000 + (k << 23));
	else
		twopk = set_float_word(0x3f800000 + ((k + 100) << 23));
	c = x - t * (P1 + t * P2);
	if (k == 0)
		return (1.0 - ((x * c) / (c - (float)2.0) - x));
	y = 1.0 - ((lo - (x * c) / ((float)2.0 - c)) - hi);
	if (k >= -125)
	{
		if (k == 128)
			return (y * 2.0F * 0x1p127F);
		return (y * twopk);
	}
	return (y * twopk * TWOM100);
}

static double	get_components(double x, uint32_t hx, int32_t xsb)
{
	double		hi;
	double		lo;
	int32_t		k;

	k = 0;
	hi = 0.0;
	lo = 0.0;
	if (hx > 0x3eb17218)
	{
		k = INVLN2 * x + g_half[xsb];
		hi = x - ((float)k) * g_ln2hi[0];
		lo = ((float)k) * g_ln2lo[0];
		if (hx < 0x3F851592)
		{
			hi = x - g_ln2hi[xsb];
			lo = g_ln2lo[xsb];
			k = 1 - xsb - xsb;
		}
		x = (hi - lo);
	}
	else if (hx < 0x39000000 && HUGE2 + x > 1.0)
		return (1.0 + x);
	else if (hx >= 0x39000000)
		k = 0;
	return (compute(x, hi, lo, k));
}

float			ft_expf(float x)
{
	int32_t		xsb;
	uint32_t	hx;

	hx = get_float_word(x);
	xsb = (hx >> 31) & 1;
	hx &= 0x7fffffff;
	if (hx >= 0x42b17218)
	{
		if (hx > 0x7f800000)
			return (x + x);
		if (hx == 0x7f800000)
			return (xsb == 0) ? x : 0.0;
		if (x > O_THRESHOLD)
			return (HUGE2 * HUGE2);
		if (x < U_THRESHOLD)
			return (TWOM100 * TWOM100);
	}
	return (get_components(x, hx, xsb));
}
