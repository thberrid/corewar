/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:51:24 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/15 12:59:19 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float		ft_maxf(float a, float b)
{
	return (a > b ? a : b);
}

double		ft_max(double a, double b)
{
	return (a > b ? a : b);
}

long double	ft_maxl(long double a, long double b)
{
	return (a > b ? a : b);
}
