/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_v.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:07:30 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 08:35:12 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftvectors/vec4/t_vec4_t.h"

t_vec4f	v4f_addv(t_vec4f *v1, t_vec4f *v2)
{
	t_vec4f	r;

	r.x = v1->x + v2->x;
	r.y = v1->y + v2->y;
	r.z = v1->z + v2->z;
	r.w = v1->w + v2->w;
	return (r);
}

t_vec4f	v4f_subv(t_vec4f *v1, t_vec4f *v2)
{
	t_vec4f	r;

	r.x = v1->x - v2->x;
	r.y = v1->y - v2->y;
	r.z = v1->z - v2->z;
	r.w = v1->w - v2->w;
	return (r);
}

t_vec4f	v4f_mulv(t_vec4f *v1, t_vec4f *v2)
{
	t_vec4f	r;

	r.x = v1->x * v2->x;
	r.y = v1->y * v2->y;
	r.z = v1->z * v2->z;
	r.w = v1->w * v2->w;
	return (r);
}
