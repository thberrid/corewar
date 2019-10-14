/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:36:17 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 08:30:11 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftvectors/vec4/t_vec4_t.h"
#include "ftmath.h"

t_dbl__	v4_norm(t_vec4 *v)
{
	return (ft_sqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w));
}

t_vec4	v4_normalize(t_vec4 *v)
{
	t_dbl__	l;
	t_vec4	r;

	if ((l = v4_norm(v)) == 0.0)
		return (*v);
	r.x = v->x / l;
	r.y = v->y / l;
	r.z = v->z / l;
	r.w = v->w / l;
	return (r);
}
