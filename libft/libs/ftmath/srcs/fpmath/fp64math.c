/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp64math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 06:00:15 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/23 07:20:05 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath/fpmath.h"

uint32_t		get_high_word(double x)
{
	t_ieee_double_shape_type	gh_u;

	gh_u.value = x;
	return (gh_u.parts.msw);
}

uint32_t		get_low_word(double x)
{
	t_ieee_double_shape_type	gh_u;

	gh_u.value = x;
	return (gh_u.parts.lsw);
}

void			insert_word(double *d, uint32_t high, uint32_t low)
{
	t_ieee_double_shape_type	iw_u;

	iw_u.parts.msw = high;
	iw_u.parts.lsw = low;
	*d = iw_u.value;
}
