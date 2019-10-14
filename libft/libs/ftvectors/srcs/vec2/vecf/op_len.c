/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:36:17 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/18 11:20:49 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftvectors/vec2/t_vec2_t.h"
#include "ftmath.h"

t_flt__		v2f_norm(t_vec2f *v)
{
	return (ft_sqrtf(v->x * v->x + v->y * v->y));
}

t_vec2f		v2f_normalize(t_vec2f *v)
{
	t_flt__	l;
	t_vec2f	r;

	if ((l = v2f_norm(v)) == 0.0f)
		return (*v);
	r.x = v->x / l;
	r.y = v->y / l;
	return (r);
}
