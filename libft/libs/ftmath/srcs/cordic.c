/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cordic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:17:46 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/19 10:57:46 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath/cordic.h"
#include "ftmath.h"
#include "ftio.h"
#include <stdlib.h>

long double	g_k_tab[TAB_SIZE] = {
	0.7853981633974482789994909,
	0.0996686524911620380651200,
	0.0099996666866652376276514,
	0.0009999996666668667898159,
	0.0000999999996666666682733,
	0.0000099999999996666679423,
	0.0000009999999999996666473,
	0.0000000999999999999996646,
	0.0000000100000000000000002,
	0.0000000010000000000000001,
	0.0000000001000000000000000,
	0.0000000000100000000000000,
	0.0000000000010000000000000,
	0.0000000000001000000000000,
	0.0000000000000100000000000,
	0.0000000000000010000000000
};

double	ft_tan(double an)
{
	int		k;
	double	x;
	double	y;
	double	tmp;

	k = 0;
	x = 1;
	y = 0;
	while (an >= EPSILON)
	{
		while (an < (tmp = (k > TAB_SIZE ? ft_pow(10.0, -k) : g_k_tab[k])))
			k++;
		an -= tmp;
		tmp = x;
		x = x - ft_pow(10.0, -k) * y;
		y = y + ft_pow(10.0, -k) * tmp;
	}
	return (y / x);
}

double	ft_cos(double an)
{
	double	tan;

	tan = ft_tan(an);
	return (1.0 / ft_sqrt(1 + tan * tan));
}

double	ft_sin(double an)
{
	double	tan;

	tan = ft_tan(an);
	return (tan / ft_sqrt(1 + tan * tan));
}
