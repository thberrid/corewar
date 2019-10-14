/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 07:33:40 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/23 10:33:14 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include <inttypes.h>
#include "ftmath/k_cos.h"
#include "ftmath/k_sin.h"
#include "ftmath/fpmath.h"

double	ft_cos(double x)
{
	double	y[2];
	double	z;
	int32_t	n;

	z = 0.0;
	n = get_high_word(x) & 0x7fffffff;
	if (n <= 0x3fe921fb)
	{
		if (n < 0x3e46a09e)
			if (((int)x) == 0)
				return (1.0);
		return (ft_kernel_cos(x, z));
	}
	else if (n >= 0x7ff00000)
		return (x - x);
	n = ft_rem_pio2(x, y);
	if (!(n & 3))
		return (ft_kernel_cos(y[0], y[1]));
	if ((n & 3) == 1)
		return (-ft_kernel_sin(y[0], y[1], 1));
	if ((n & 3) == 2)
		return (-ft_kernel_cos(y[0], y[1]));
	return (ft_kernel_sin(y[0], y[1], 1));
}
