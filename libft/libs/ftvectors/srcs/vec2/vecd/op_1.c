/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:07:30 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/18 10:57:58 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftvectors/vec2/t_vec2_t.h"

t_vec2	v2_add1(t_vec2 *v, t_dbl__ i)
{
	t_vec2	r;

	r.x = v->x + i;
	r.y = v->y + i;
	return (r);
}

t_vec2	v2_sub1(t_vec2 *v, t_dbl__ i)
{
	t_vec2	r;

	r.x = v->x - i;
	r.y = v->y - i;
	return (r);
}

t_vec2	v2_mul1(t_vec2 *v, t_dbl__ i)
{
	t_vec2	r;

	r.x = v->x * i;
	r.y = v->y * i;
	return (r);
}

t_vec2	v2_div(t_vec2 *v, t_dbl__ i)
{
	t_vec2	r;

	r.x = v->x / i;
	r.y = v->y / i;
	return (r);
}
