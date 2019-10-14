/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 11:29:27 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/15 11:39:34 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"
#include "ftmath.h"

float		ft_sqrtf(float nb)
{
	int		i;
	float	a;

	i = 0;
	if (nb < 0.0)
		return (-1);
	if (nb == 0.0 || nb == 1.0)
		return (nb);
	if (nb > 7447441.0f)
		return (2.0 * ft_sqrtf(nb / 4.0));
	a = ft_powf(10, ft_unsignedlen((uintmax_t)nb) / 2.0);
	while (++i < 20)
		a = 0.5 * (a + (nb / a));
	return (a);
}

double		ft_sqrt(double nb)
{
	int		i;
	double	a;

	i = 0;
	if (nb < 0.0)
		return (-1);
	if (nb == 0.0 || nb == 1.0)
		return (nb);
	if (nb > 7447441.0)
		return (2.0 * ft_sqrt(nb / 4.0));
	a = ft_pow(10, ft_unsignedlen((uintmax_t)nb) / 2.0);
	while (++i < 20)
		a = 0.5 * (a + (nb / a));
	return (a);
}

long double	ft_sqrtl(long double nb)
{
	int			i;
	long double	a;

	i = 0;
	if (nb < 0.0)
		return (-1);
	if (nb == 0.0 || nb == 1.0)
		return (nb);
	if (nb > 7447441.0)
		return (2.0 * ft_sqrtl(nb / 4.0));
	a = ft_powl(10, ft_unsignedlen((uintmax_t)nb) / 2.0);
	while (++i < 20)
		a = 0.5 * (a + (nb / a));
	return (a);
}
