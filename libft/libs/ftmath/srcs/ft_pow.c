/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 11:35:28 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/19 10:24:52 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float		ft_powf(float x, int y)
{
	float	temp;

	if (y == 0)
		return (1);
	temp = ft_powf(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	else
	{
		if (y > 0)
			return (x * temp * temp);
		else
			return ((temp * temp) / x);
	}
}

double		ft_pow(double x, int y)
{
	double	temp;

	if (y == 0)
		return (1);
	temp = ft_pow(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	else
	{
		if (y > 0)
			return (x * temp * temp);
		else
			return ((temp * temp) / x);
	}
}

long double	ft_powl(long double x, int y)
{
	long double	temp;

	if (y == 0)
		return (1);
	temp = ft_powl(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	else
	{
		if (y > 0)
			return (x * temp * temp);
		else
			return ((temp * temp) / x);
	}
}
