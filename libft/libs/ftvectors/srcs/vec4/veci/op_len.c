/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:36:17 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 19:24:46 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftvectors/vec4/t_vec4_t.h"
#include "ftmath.h"

t_dbl__		v4i_norm(t_vec4i *v)
{
	return (ft_sqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w));
}

t_flt__		v4i_normf(t_vec4i *v)
{
	return (ft_sqrtf(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w));
}

t_vec4i		v4i_normalize(t_vec4i *v)
{
	t_dbl__	l;
	t_vec4i	r;

	if ((l = v4i_norm(v)) == 0.0)
		return (*v);
	r.x = v->x / l;
	r.y = v->y / l;
	r.z = v->z / l;
	r.w = v->w / l;
	return (r);
}
