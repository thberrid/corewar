/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:49:13 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/02 21:58:17 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>

float		ft_absf(float x)
{
	return (x < 0 ? -x : x);
}

double		ft_abs(double x)
{
	return (x < 0 ? -x : x);
}

long double	ft_absl(long double x)
{
	return (x < 0 ? -x : x);
}
