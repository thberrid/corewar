/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:14:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 18:38:44 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmatrix/t_midx.h"
#include "ftmatrix/t_mat4.h"
#include "ftlib.h"

/*
**	Gauss-Jordan method:
**	Reminder:
**		valid operations are :
**			Swapping two rows,
**			Multiplying a row by a nonzero number,
**			Adding a multiple of one row to another row.
**
**		| 5  2  3 |
**	A = | 4  9  9 |
**		| 7 10  6 |
**
**	1 - augment the matrix to the right with identity:
**
**		| 5  2  3 | 1  0  0 |
**	A = | 4  9  9 | 0  1  0 |
**		| 7 10  6 | 0  0  1 |
**
**	2 - proceede to the reduction:
**
**	p = 1
**	pivots: (n-ieme ligne)
**		TAij = ((Ann * Aij - Ain * Anj) / p)
**
**		TA21 = ((Ann * A21 - A2n * An1) / p) = ((5 * 4 - 4 * 5) / p) = 0
**		TA22 = ((Ann * A22 - A2n * An2) / p) = ((5 * 9 - 4 * 2) / p) = 37
**		TA23 = ((Ann * A23 - A2n * An3) / p) = ((5 * 9 - 4 * 3) / p) = 33
**		TA24 = ((Ann * A24 - A2n * An4) / p) = ((5 * 0 - 4 * 1) / p) = -4
**
**		TA31 = ((A11 * A31 - A31 * A11) / p) = ((5 * 7 - 7 * 5) / p) = 0
**									...
**		| 5  2  3 | 1  0  0 |
**	TA= | 0 37 33 |-4 .. .. |
**		| 0 .. .. |   .. .. |
**	p = Ann
**	A = TA
**
**	int		x;
**	int		y;
**	double	p;
**
**	for (int n = 1; n < 4; ++s)
**	{
**		p = 1.0;
**		for (y = 1; y < 4; ++y)
**		{
**			if (y == n)
**				continue ;
**			for (x = 1; x < 2*4; ++x)
**			{
**				R[y][x] = ((M[n][n] * M[y][x] - M[y][n] * M[n][x]) / p);
**			}
**		}
**		p = M[n][n];
**		M = R;
**	}
*/

/*
**	Tyx = ((Ann * Ayx - Ayn * Anx) / p)
*/

static double	gauss_bareiss(const int s, double *const t, double *const r)
{
	register char	x;
	register char	y;
	double			n;
	double			np;
	double			sp;

	y = 0;
	n = (s > 0 ? gauss_bareiss(s - 1, t, r) : 1.0);
	np = t[s + s * 4];
	while (y < 16)
	{
		if ((y >> 2) == s && (y += 4))
			continue ;
		x = 4;
		sp = t[s + y];
		while (x-- > 0)
		{
			t[x + y] = (np * t[x + y] - sp * t[x + s * 4]) / n;
			r[x + y] = (np * r[x + y] - sp * r[x + s * 4]) / n;
		}
		y += 4;
	}
	return (np);
}

t_mat4			m4_inv(t_mat4 *m)
{
	register int	i;
	t_mat4			t;
	t_mat4			res;
	double			det;

	i = -1;
	while (++i < MLN)
	{
		t.m[i] = m->m[i];
		res.m[i] = !(i % 5);
	}
	det = gauss_bareiss(3, t.m, res.m);
	while (i-- > 0)
		res.m[i] /= det;
	return (res);
}
