/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:18:31 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 19:20:03 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftvectors/t_vec2.h"

t_vec2	set_vec2(t_vec2 *p, uint32_t c, ...)
{
	t_vec2	v;
	va_list	ap;

	v.x = 0.0;
	v.y = 0.0;
	va_start(ap, c);
	if (c && c--)
		v.x = va_arg(ap, t_dbl__);
	if (c && c--)
		v.y = va_arg(ap, t_dbl__);
	va_end(ap);
	if (p)
		*p = v;
	return (v);
}

t_vec2i	set_vec2i(t_vec2i *p, uint32_t c, ...)
{
	t_vec2i	v;
	va_list	ap;

	v.x = 0;
	v.y = 0;
	va_start(ap, c);
	if (c && c--)
		v.x = va_arg(ap, t_int__);
	if (c && c--)
		v.y = va_arg(ap, t_int__);
	va_end(ap);
	if (p)
		*p = v;
	return (v);
}

t_vec2f	set_vec2f(t_vec2f *p, uint32_t c, ...)
{
	t_vec2f	v;
	va_list	ap;

	v.x = 0.0f;
	v.y = 0.0f;
	va_start(ap, c);
	if (c && c--)
		v.x = (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		v.y = (t_flt__)va_arg(ap, t_dbl__);
	va_end(ap);
	if (p)
		*p = v;
	return (v);
}
