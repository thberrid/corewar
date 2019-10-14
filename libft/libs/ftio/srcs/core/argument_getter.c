/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_getter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:23:09 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/25 10:16:40 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftio/ft_core.h"
#include "ftio/ft_types.h"
#include "ftlib.h"

t_val	get_pointer(va_list *ap, const int l)
{
	t_val	ret;

	(void)l;
	ret.lf = 0.0;
	ret.p = ((void *)va_arg(*ap, intptr_t));
	return (ret);
}

t_val	get_double(va_list *ap, const int l)
{
	t_val	ret;

	ret.lf = 0.0;
	if (LEN_MD_CHRS[l] == 'L')
		ret.lf = ((long double)va_arg(*ap, long double));
	else
		ret.f = ((double)va_arg(*ap, double));
	return (ret);
}

t_val	get_integer(va_list *ap, const int l)
{
	t_val	ret;

	ret.lf = 0.0;
	if (LEN_MD_CHRS[l] == 'q')
		ret.i = ((t_ll)va_arg(*ap, t_quad));
	else if (LEN_MD_CHRS[l] == 'j')
		ret.i = ((t_ll)va_arg(*ap, intmax_t));
	else if (LEN_MD_CHRS[l] == 'z')
		ret.i = ((t_ll)va_arg(*ap, size_t));
	else if (LEN_MD_CHRS[l] == 'Z')
		ret.i = ((t_ll)va_arg(*ap, ssize_t));
	else if (LEN_MD_CHRS[l] == 't')
		ret.i = ((t_ll)va_arg(*ap, ptrdiff_t));
	else if (LEN_MD_CHRS[l] == 'l')
		ret.i = ((t_ll)va_arg(*ap, long));
	else if (LEN_MD_CHRS[l] == 'L')
		ret.i = ((t_ll)va_arg(*ap, t_ll));
	else if (LEN_MD_CHRS[l] == 'h')
		ret.i = ((t_ll)va_arg(*ap, int));
	else if (LEN_MD_CHRS[l] == 'H')
		ret.i = ((t_ll)va_arg(*ap, int));
	else
		ret.i = ((t_ll)va_arg(*ap, int));
	return (ret);
}
