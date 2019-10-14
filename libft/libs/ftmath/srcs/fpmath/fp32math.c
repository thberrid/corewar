/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp32math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 06:59:33 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/23 07:06:13 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath/fpmath.h"

uint32_t	get_float_word(float x)
{
	t_ieee_float_shape_type	gf_u;

	gf_u.value = x;
	return (gf_u.word);
}

float		set_float_word(uint32_t val)
{
	t_ieee_float_shape_type sf_u;

	sf_u.word = val;
	return (sf_u.value);
}
