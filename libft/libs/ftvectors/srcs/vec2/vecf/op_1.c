/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:07:30 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/18 11:14:44 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftvectors/vec2/t_vec2_t.h"

t_vec2f	v2f_add1(t_vec2f *v, t_flt__ i)
{
	t_vec2f	r;

	r.x = v->x + i;
	r.y = v->y + i;
	return (r);
}

t_vec2f	v2f_sub1(t_vec2f *v, t_flt__ i)
{
	t_vec2f	r;

	r.x = v->x - i;
	r.y = v->y - i;
	return (r);
}

t_vec2f	v2f_mul1(t_vec2f *v, t_flt__ i)
{
	t_vec2f	r;

	r.x = v->x * i;
	r.y = v->y * i;
	return (r);
}

t_vec2f	v2f_div1(t_vec2f *v, t_flt__ i)
{
	t_vec2f	r;

	r.x = v->x / i;
	r.y = v->y / i;
	return (r);
}
