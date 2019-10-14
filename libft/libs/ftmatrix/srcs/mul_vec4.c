/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_vec4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 19:51:27 by baurens           #+#    #+#             */
/*   Updated: 2019/09/30 19:23:25 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmatrix/t_midx.h"
#include "ftmatrix/t_mat4.h"
#include "ftvector.h"

t_vec4	m4_mulv(const t_mat4 *m, const t_vec4 *v)
{
	t_vec4	r;

	r.x = m->m[M00] * v->x + m->m[M10] * v->y
		+ m->m[M20] * v->z + m->m[M30] * v->w;
	r.y = m->m[M01] * v->x + m->m[M11] * v->y
		+ m->m[M21] * v->z + m->m[M31] * v->w;
	r.z = m->m[M02] * v->x + m->m[M12] * v->y
		+ m->m[M22] * v->z + m->m[M32] * v->w;
	r.w = m->m[M03] * v->x + m->m[M13] * v->y
		+ m->m[M23] * v->z + m->m[M33] * v->w;
	return (r);
}

t_vec4f	m4_mulvf(const t_mat4 *m, const t_vec4f *v)
{
	t_vec4f	r;

	r.x = m->m[M00] * v->x + m->m[M10] * v->y
		+ m->m[M20] * v->z + m->m[M30] * v->w;
	r.y = m->m[M01] * v->x + m->m[M11] * v->y
		+ m->m[M21] * v->z + m->m[M31] * v->w;
	r.z = m->m[M02] * v->x + m->m[M12] * v->y
		+ m->m[M22] * v->z + m->m[M32] * v->w;
	r.w = m->m[M03] * v->x + m->m[M13] * v->y
		+ m->m[M23] * v->z + m->m[M33] * v->w;
	return (r);
}

t_vec4i	m4_mulvi(const t_mat4 *m, const t_vec4i *v)
{
	t_vec4i	r;

	r.x = m->m[M00] * v->x + m->m[M10] * v->y
		+ m->m[M20] * v->z + m->m[M30] * v->w;
	r.y = m->m[M01] * v->x + m->m[M11] * v->y
		+ m->m[M21] * v->z + m->m[M31] * v->w;
	r.z = m->m[M02] * v->x + m->m[M12] * v->y
		+ m->m[M22] * v->z + m->m[M32] * v->w;
	r.w = m->m[M03] * v->x + m->m[M13] * v->y
		+ m->m[M23] * v->z + m->m[M33] * v->w;
	return (r);
}
