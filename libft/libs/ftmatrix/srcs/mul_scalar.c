/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_scalar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 19:43:49 by baurens           #+#    #+#             */
/*   Updated: 2019/09/28 20:02:55 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmatrix/t_midx.h"
#include "ftmatrix/t_mat4.h"

t_mat4	m4_muli(t_mat4 *m, double d)
{
	register t_midx__	x;
	register t_midx__	y;
	t_mat4				res;

	y = 0;
	while (y < 16)
	{
		x = 0;
		while (x < 4)
		{
			res.m[y + x] = m1->m[x + y] * d;
			++x;
		}
		y += 4;
	}
	return (res);
}
