/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:07:30 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 12:48:07 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftvectors/vec3/t_vec3_t.h"

t_vec3i	v3i_addc(t_vec3i *v, uint32_t c, ...)
{
	t_vec3i	r;
	va_list	ap;

	r.x = v->x;
	r.y = v->y;
	r.z = v->z;
	va_start(ap, c);
	if (c && c--)
		r.x += va_arg(ap, t_int__);
	if (c && c--)
		r.y += va_arg(ap, t_int__);
	if (c && c--)
		r.z += va_arg(ap, t_int__);
	va_end(ap);
	return (r);
}

t_vec3i	v3i_subc(t_vec3i *v, uint32_t c, ...)
{
	t_vec3i	r;
	va_list	ap;

	r.x = v->x;
	r.y = v->y;
	r.z = v->z;
	va_start(ap, c);
	if (c && c--)
		r.x -= va_arg(ap, t_int__);
	if (c && c--)
		r.y -= va_arg(ap, t_int__);
	if (c && c--)
		r.z -= va_arg(ap, t_int__);
	va_end(ap);
	return (r);
}

t_vec3i	v3i_mulc(t_vec3i *v, uint32_t c, ...)
{
	t_vec3i	r;
	va_list	ap;

	r.x = v->x;
	r.y = v->y;
	r.z = v->z;
	va_start(ap, c);
	if (c && c--)
		r.x *= va_arg(ap, t_int__);
	if (c && c--)
		r.y *= va_arg(ap, t_int__);
	if (c && c--)
		r.z *= va_arg(ap, t_int__);
	va_end(ap);
	return (r);
}
