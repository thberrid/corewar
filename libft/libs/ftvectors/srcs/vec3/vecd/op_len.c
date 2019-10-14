/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:36:17 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/18 12:53:43 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftvectors/vec3/t_vec3_t.h"
#include "ftmath.h"

t_dbl__	v3_norm(t_vec3 *v)
{
	return (ft_sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

t_vec3	v3_normalize(t_vec3 *v)
{
	t_dbl__	l;
	t_vec3	r;

	if ((l = v3_norm(v)) == 0.0)
		return (*v);
	r.x = v->x / l;
	r.y = v->y / l;
	r.z = v->z / l;
	return (r);
}
