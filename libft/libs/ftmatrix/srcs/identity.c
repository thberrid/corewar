/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 10:35:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/28 20:02:38 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmatrix/t_midx.h"
#include "ftmatrix/t_mat4.h"

t_mat4	m4_identity(void)
{
	t_mat4				res;

	res.m[M00] = 1.0;
	res.m[M10] = 0.0;
	res.m[M20] = 0.0;
	res.m[M30] = 0.0;
	res.m[M01] = 0.0;
	res.m[M11] = 1.0;
	res.m[M21] = 0.0;
	res.m[M31] = 0.0;
	res.m[M02] = 0.0;
	res.m[M12] = 0.0;
	res.m[M22] = 1.0;
	res.m[M32] = 0.0;
	res.m[M03] = 0.0;
	res.m[M13] = 0.0;
	res.m[M23] = 0.0;
	res.m[M33] = 1.0;
	return (res);
}
