/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:08:00 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/09 15:49:22 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_DISABLE_WARNINGS

#include "ftmath.h"
#include "ftio.h"

static double	ft_get_integ(double n, uint64_t *integ)
{
	double		base_n;
	double		base_n_2;
	uint64_t	n2;

	*integ = 0;
	while (n >= FT_E)
	{
		n2 = 1;
		base_n = FT_E;
		base_n_2 = FT_E * FT_E;
		while (n >= base_n_2)
		{
			base_n = base_n_2;
			base_n_2 *= base_n_2;
			n2 <<= 1;
		}
		n /= base_n;
		*integ |= n2;
	}
	return (n);
}

double			ft_log(double nb)
{
	uint16_t	i;
	uint64_t	integ;
	uint64_t	frac;

	if (nb < 1)
		return (ft_log(1.0 / nb));
	frac = 0;
	nb = ft_get_integ(nb, &integ);
	i = 0;
	while (i++ < 52)
	{
		nb *= nb;
		frac <<= 1;
		if (nb >= FT_E)
		{
			frac |= 1;
			nb /= FT_E;
		}
	}
	return (integ + ((double)frac / (1LU << 52)));
}

float			ft_logf(float nb)
{
	uint16_t	i;
	uint64_t	integ;
	uint64_t	frac;

	if (nb < 1)
		return (ft_logf(1.0 / nb));
	frac = 0;
	nb = ft_get_integ(nb, &integ);
	i = 0;
	while (i++ < 23)
	{
		nb *= nb;
		frac <<= 1;
		if (nb >= FT_E)
		{
			frac |= 1;
			nb /= FT_E;
		}
	}
	return (integ + ((float)frac / (1LU << 23)));
}
