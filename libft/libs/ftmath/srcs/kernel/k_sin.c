/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 07:41:54 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/23 07:50:27 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath/k_sin.h"

double	ft_kernel_sin(double x, double y, int iy)
{
	double	z;
	double	r;
	double	v;
	double	w;

	z = x * x;
	w = z * z;
	r = S2 + z * (S3 + z * S4) + z * w * (S5 + z * S6);
	v = z * x;
	if (iy == 0)
		return (x + v * (S1 + z * r));
	return (x - ((z * (5.00000000000000000000e-01 * y - v * r) - y) - v * S1));
}
