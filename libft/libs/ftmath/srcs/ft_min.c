/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:51:54 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/15 12:59:14 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float		ft_minf(float a, float b)
{
	return (a < b ? a : b);
}

double		ft_min(double a, double b)
{
	return (a < b ? a : b);
}

long double	ft_minl(long double a, long double b)
{
	return (a < b ? a : b);
}
