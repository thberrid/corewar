/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:07:30 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 08:35:03 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftvectors/vec4/t_vec4_t.h"

t_vec4f	v4f_add1(t_vec4f *v, t_flt__ i)
{
	t_vec4f	r;

	r.x = v->x + i;
	r.y = v->y + i;
	r.z = v->z + i;
	r.w = v->w + i;
	return (r);
}

t_vec4f	v4f_sub1(t_vec4f *v, t_flt__ i)
{
	t_vec4f	r;

	r.x = v->x - i;
	r.y = v->y - i;
	r.z = v->z - i;
	r.w = v->w - i;
	return (r);
}

t_vec4f	v4f_mul1(t_vec4f *v, t_flt__ i)
{
	t_vec4f	r;

	r.x = v->x * i;
	r.y = v->y * i;
	r.z = v->z * i;
	r.w = v->w * i;
	return (r);
}

t_vec4f	v4f_div1(t_vec4f *v, t_flt__ i)
{
	t_vec4f	r;

	r.x = v->x / i;
	r.y = v->y / i;
	r.z = v->z / i;
	r.w = v->w / i;
	return (r);
}
