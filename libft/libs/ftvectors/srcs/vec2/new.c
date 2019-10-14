/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:27:08 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 19:20:04 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftvectors/t_vec2.h"

t_vec2	vec2(t_dbl__ x, t_dbl__ y)
{
	t_vec2	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vec2i	vec2i(t_int__ x, t_int__ y)
{
	t_vec2i	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vec2f	vec2f(t_flt__ x, t_flt__ y)
{
	t_vec2f	v;

	v.x = x;
	v.y = y;
	return (v);
}
