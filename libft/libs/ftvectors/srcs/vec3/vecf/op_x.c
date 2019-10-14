/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:07:30 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 12:46:47 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftvectors/vec3/t_vec3_t.h"

t_vec3f	v3f_addc(t_vec3f *v, uint32_t c, ...)
{
	t_vec3f	r;
	va_list	ap;

	r.x = v->x;
	r.y = v->y;
	r.z = v->z;
	va_start(ap, c);
	if (c && c--)
		r.x += (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		r.y += (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		r.z += (t_flt__)va_arg(ap, t_dbl__);
	va_end(ap);
	return (r);
}

t_vec3f	v3f_subc(t_vec3f *v, uint32_t c, ...)
{
	t_vec3f	r;
	va_list	ap;

	r.x = v->x;
	r.y = v->y;
	r.z = v->z;
	va_start(ap, c);
	if (c && c--)
		r.x -= (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		r.y -= (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		r.z -= (t_flt__)va_arg(ap, t_dbl__);
	va_end(ap);
	return (r);
}

t_vec3f	v3f_mulc(t_vec3f *v, uint32_t c, ...)
{
	t_vec3f	r;
	va_list	ap;

	r.x = v->x;
	r.y = v->y;
	r.z = v->z;
	va_start(ap, c);
	if (c && c--)
		r.x *= (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		r.y *= (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		r.z *= (t_flt__)va_arg(ap, t_dbl__);
	va_end(ap);
	return (r);
}
