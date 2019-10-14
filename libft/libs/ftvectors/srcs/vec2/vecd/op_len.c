/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:36:17 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/18 11:11:16 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftvectors/vec2/t_vec2_t.h"
#include "ftmath.h"

t_dbl__		v2_norm(t_vec2 *v)
{
	return (ft_sqrt(v->x * v->x + v->y * v->y));
}

t_vec2		v2_normalize(t_vec2 *v)
{
	t_dbl__	l;
	t_vec2	r;

	if ((l = v2_norm(v)) == 0.0)
		return (*v);
	r.x = v->x / l;
	r.y = v->y / l;
	return (r);
}
