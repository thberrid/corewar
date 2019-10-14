/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:18:31 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 19:20:32 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftvectors/t_vec4.h"

t_vec4	vec4(t_dbl__ x, t_dbl__ y, t_dbl__ z, t_dbl__ w)
{
	t_vec4	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return (v);
}

t_vec4i	vec4i(t_int__ x, t_int__ y, t_int__ z, t_int__ w)
{
	t_vec4i	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return (v);
}

t_vec4f	vec4f(t_flt__ x, t_flt__ y, t_flt__ z, t_flt__ w)
{
	t_vec4f	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return (v);
}
