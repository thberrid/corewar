/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:07:30 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 19:31:55 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftvectors/vec4/t_vec4_t.h"

t_vec4f	v4f_addc(t_vec4f *v, uint32_t c, ...)
{
	t_vec4f	r;
	va_list	ap;

	r.x = v->x;
	r.y = v->y;
	r.z = v->z;
	r.w = v->w;
	va_start(ap, c);
	if (c && c--)
		r.x += (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		r.y += (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		r.z += (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		r.w += (t_flt__)va_arg(ap, t_dbl__);
	va_end(ap);
	return (r);
}

t_vec4f	v4f_subc(t_vec4f *v, uint32_t c, ...)
{
	t_vec4f	r;
	va_list	ap;

	r.x = v->x;
	r.y = v->y;
	r.z = v->z;
	r.w = v->w;
	va_start(ap, c);
	if (c && c--)
		r.x -= (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		r.y -= (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		r.z -= (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		r.w -= (t_flt__)va_arg(ap, t_dbl__);
	va_end(ap);
	return (r);
}

t_vec4f	v4f_mulc(t_vec4f *v, uint32_t c, ...)
{
	t_vec4f	r;
	va_list	ap;

	r.x = v->x;
	r.y = v->y;
	r.z = v->z;
	r.w = v->w;
	va_start(ap, c);
	if (c && c--)
		r.x *= (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		r.y *= (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		r.z *= (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		r.w *= (t_flt__)va_arg(ap, t_dbl__);
	va_end(ap);
	return (r);
}
