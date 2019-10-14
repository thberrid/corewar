/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:15:59 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/28 20:03:04 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmatrix/t_midx.h"
#include "ftmatrix/t_mat4.h"

/*
**	TODO:
**		lookup the Strassen algorithm to possibly optimise this
**		https://en.wikipedia.org/wiki/Strassen_algorithm
**		https://fr.wikipedia.org/wiki/Algorithme_de_Strassen
*/

t_mat4	m4_mul(t_mat4 *m1, t_mat4 *m2)
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
			res.m[y + x] = (m1->m[y] * m2->m[x]) + (m1->m[1 + y] * m2->m[x + 4])
			+ (m1->m[2 + y] * m2->m[x + 8]) + (m1->m[3 + y] * m2->m[x + 12]);
			++x;
		}
		y += 4;
	}
	return (res);
}
