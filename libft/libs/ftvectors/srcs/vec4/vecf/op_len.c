/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:36:17 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 08:35:10 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftvectors/vec4/t_vec4_t.h"
#include "ftmath.h"

t_flt__	v4f_norm(t_vec4f *v)
{
	return (ft_sqrtf(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w));
}

t_vec4f	v4f_normalize(t_vec4f *v)
{
	t_flt__	l;
	t_vec4f	r;

	if ((l = v4f_norm(v)) == 0.0f)
		return (*v);
	r.x = v->x / l;
	r.y = v->y / l;
	r.z = v->z / l;
	r.w = v->w / l;
	return (r);
}
