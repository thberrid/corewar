/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:53:22 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/27 15:52:18 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmatrix/t_midx.h"
#include "ftmatrix/t_mat4.h"

/*
**		| a b c d |
**		| e f g h |
**		| i j k l |
**		| m n o p |
**
**	det =
**		| f g h |
**	a * | j k l |
**		| n o p |
**	-
**		| e g h |
**	b * | i k l |
**		| m o p |
**	+
**		| h e f |
**	c * | l i j |
**		| p m n |
**	-
**		| e f g |
**	d * | i j k |
**		| m n o |
**
**	det =
**	+a(fkp-flo-gjp+gln+hjo-hkn)
**	-b(ekp-elo-gip+glm+hio-hkm)
**	+c(ejp-eln-fip+flm+hin-hjm)
**	-d(ejo-ekn-fio+fkm+gin-gjm)
**
**   a * (f * k * p - f * l * o - g * j * p + g * l * n + h * j * o - h * k * n)
** - b * (e * k * p - e * l * o - g * i * p + g * l * m + h * i * o - h * k * m)
** + c * (e * j * p - e * l * n - f * i * p + f * l * m + h * i * n - h * j * m)
** - d * (e * j * o - e * k * n - f * i * o + f * k * m + g * i * n - g * j * m)
*/

double	m4_det(t_mat4 *m)
{
	double const *const t = m->m;

	return (t[0] * (t[5] * t[10] * t[15] - t[5] * t[11] * t[14]
		- t[6] * t[9] * t[15] + t[6] * t[11] * t[13]
		+ t[7] * t[9] * t[14] - t[7] * t[10] * t[13])
	- t[1] * (t[4] * t[10] * t[15] - t[4] * t[11] * t[14]
		- t[6] * t[8] * t[15] + t[6] * t[11] * t[12]
		+ t[7] * t[8] * t[14] - t[7] * t[10] * t[12])
	+ t[2] * (t[4] * t[9] * t[15] - t[4] * t[11] * t[13]
		- t[5] * t[8] * t[15] + t[5] * t[11] * t[12]
		+ t[7] * t[8] * t[13] - t[7] * t[9] * t[12])
	- t[3] * (t[4] * t[9] * t[14] - t[4] * t[10] * t[13]
		- t[5] * t[8] * t[14] + t[5] * t[10] * t[12]
		+ t[6] * t[8] * t[13] - t[6] * t[9] * t[12]));
}
