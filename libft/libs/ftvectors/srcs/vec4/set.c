/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:18:31 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 19:20:44 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftvectors/t_vec4.h"

t_vec4	set_vec4(t_vec4 *p, uint32_t c, ...)
{
	t_vec4	v;
	va_list	ap;

	v.x = 0.0;
	v.y = 0.0;
	v.z = 0.0;
	v.w = 0.0;
	va_start(ap, c);
	if (c && c--)
		v.x = va_arg(ap, t_dbl__);
	if (c && c--)
		v.y = va_arg(ap, t_dbl__);
	if (c && c--)
		v.z = va_arg(ap, t_dbl__);
	if (c && c--)
		v.w = va_arg(ap, t_dbl__);
	va_end(ap);
	if (p)
		*p = v;
	return (v);
}

t_vec4i	set_vec4i(t_vec4i *p, uint32_t c, ...)
{
	t_vec4i	v;
	va_list	ap;

	v.x = 0;
	v.y = 0;
	v.z = 0;
	v.w = 0;
	va_start(ap, c);
	if (c && c--)
		v.x = va_arg(ap, t_int__);
	if (c && c--)
		v.y = va_arg(ap, t_int__);
	if (c && c--)
		v.z = va_arg(ap, t_int__);
	if (c && c--)
		v.w = va_arg(ap, t_int__);
	va_end(ap);
	if (p)
		*p = v;
	return (v);
}

t_vec4f	set_vec4f(t_vec4f *p, uint32_t c, ...)
{
	t_vec4f	v;
	va_list	ap;

	v.x = 0.0f;
	v.y = 0.0f;
	v.z = 0.0f;
	v.w = 0.0f;
	va_start(ap, c);
	if (c && c--)
		v.x = (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		v.y = (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		v.z = (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		v.w = (t_flt__)va_arg(ap, t_dbl__);
	va_end(ap);
	if (p)
		*p = v;
	return (v);
}
