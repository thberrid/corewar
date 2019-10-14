/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:07:30 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 08:30:28 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftvectors/vec4/t_vec4_t.h"

t_vec4	v4_add1(t_vec4 *v, t_dbl__ i)
{
	t_vec4	r;

	r.x = v->x + i;
	r.y = v->y + i;
	r.z = v->z + i;
	r.w = v->w + i;
	return (r);
}

t_vec4	v4_sub1(t_vec4 *v, t_dbl__ i)
{
	t_vec4	r;

	r.x = v->x - i;
	r.y = v->y - i;
	r.z = v->z - i;
	r.w = v->w - i;
	return (r);
}

t_vec4	v4_mul1(t_vec4 *v, t_dbl__ i)
{
	t_vec4	r;

	r.x = v->x * i;
	r.y = v->y * i;
	r.z = v->z * i;
	r.w = v->w * i;
	return (r);
}

t_vec4	v4_div1(t_vec4 *v, t_dbl__ i)
{
	t_vec4	r;

	r.x = v->x / i;
	r.y = v->y / i;
	r.z = v->z / i;
	r.w = v->w / i;
	return (r);
}
