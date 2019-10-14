/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:07:30 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/18 11:38:17 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftvectors/vec2/t_vec2_t.h"

t_vec2i	v2i_add1(t_vec2i *v, t_int__ i)
{
	t_vec2i	r;

	r.x = v->x + i;
	r.y = v->y + i;
	return (r);
}

t_vec2i	v2i_sub1(t_vec2i *v, t_int__ i)
{
	t_vec2i	r;

	r.x = v->x - i;
	r.y = v->y - i;
	return (r);
}

t_vec2i	v2i_mul1(t_vec2i *v, t_int__ i)
{
	t_vec2i	r;

	r.x = v->x * i;
	r.y = v->y * i;
	return (r);
}

t_vec2i	v2i_div1(t_vec2i *v, t_int__ i)
{
	t_vec2i	r;

	r.x = v->x / i;
	r.y = v->y / i;
	return (r);
}
