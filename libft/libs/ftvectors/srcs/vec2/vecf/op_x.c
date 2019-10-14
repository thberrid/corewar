/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:07:30 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 12:49:44 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftvectors/vec2/t_vec2_t.h"

t_vec2f	v2f_addc(t_vec2f *v, uint32_t c, ...)
{
	t_vec2f	r;
	va_list	ap;

	r.x = v->x;
	r.y = v->y;
	va_start(ap, c);
	if (c && c--)
		r.x += (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		r.y += (t_flt__)va_arg(ap, t_dbl__);
	va_end(ap);
	return (r);
}

t_vec2f	v2f_subc(t_vec2f *v, uint32_t c, ...)
{
	t_vec2f	r;
	va_list	ap;

	r.x = v->x;
	r.y = v->y;
	va_start(ap, c);
	if (c && c--)
		r.x -= (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		r.y -= (t_flt__)va_arg(ap, t_dbl__);
	va_end(ap);
	return (r);
}

t_vec2f	v2f_mulc(t_vec2f *v, uint32_t c, ...)
{
	t_vec2f	r;
	va_list	ap;

	r.x = v->x;
	r.y = v->y;
	va_start(ap, c);
	if (c && c--)
		r.x *= (t_flt__)va_arg(ap, t_dbl__);
	if (c && c--)
		r.y *= (t_flt__)va_arg(ap, t_dbl__);
	va_end(ap);
	return (r);
}
