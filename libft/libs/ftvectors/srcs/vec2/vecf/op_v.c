/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_v.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:07:30 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/18 11:14:24 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftvectors/vec2/t_vec2_t.h"

t_vec2f	v2f_addv(t_vec2f *v1, t_vec2f *v2)
{
	t_vec2f	r;

	r.x = v1->x + v2->x;
	r.y = v1->y + v2->y;
	return (r);
}

t_vec2f	v2f_subv(t_vec2f *v1, t_vec2f *v2)
{
	t_vec2f	r;

	r.x = v1->x - v2->x;
	r.y = v1->y - v2->y;
	return (r);
}

t_vec2f	v2f_mulv(t_vec2f *v1, t_vec2f *v2)
{
	t_vec2f	r;

	r.x = v1->x * v2->x;
	r.y = v1->y * v2->y;
	return (r);
}
