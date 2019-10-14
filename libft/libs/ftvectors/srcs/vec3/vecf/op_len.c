/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:36:17 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/18 12:54:32 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftvectors/vec3/t_vec3_t.h"
#include "ftmath.h"

t_flt__	v3f_norm(t_vec3f *v)
{
	return (ft_sqrtf(v->x * v->x + v->y * v->y + v->z * v->z));
}

t_vec3f	v3f_normalize(t_vec3f *v)
{
	t_flt__	l;
	t_vec3f	r;

	if ((l = v3f_norm(v)) == 0.0f)
		return (*v);
	r.x = v->x / l;
	r.y = v->y / l;
	r.z = v->z / l;
	return (r);
}
