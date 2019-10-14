/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_v.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:07:30 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/18 12:52:17 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftvectors/vec3/t_vec3_t.h"

t_vec3i	v3i_addv(t_vec3i *v1, t_vec3i *v2)
{
	t_vec3i	r;

	r.x = v1->x + v2->x;
	r.y = v1->y + v2->y;
	r.z = v1->z + v2->z;
	return (r);
}

t_vec3i	v3i_subv(t_vec3i *v1, t_vec3i *v2)
{
	t_vec3i	r;

	r.x = v1->x - v2->x;
	r.y = v1->y - v2->y;
	r.z = v1->z - v2->z;
	return (r);
}

t_vec3i	v3i_mulv(t_vec3i *v1, t_vec3i *v2)
{
	t_vec3i	r;

	r.x = v1->x * v2->x;
	r.y = v1->y * v2->y;
	r.z = v1->z * v2->z;
	return (r);
}
