/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_exotic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:27:11 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 02:14:45 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftio/ft_core.h"
#include "ftio/ft_types.h"
#include "ftlib.h"

char			*intmax_uoctal(t_printf *const data, t_arg *const ar)
{
	uintmax_t	v;
	char		*tab;
	int			ln;

	v = (uintmax_t)ar->val.i;
	if ((ln = ft_unsignedlen_base(v, "01234567")) > ar->prec && (v || ar->prec))
		ar->prec = ln;
	if (flag(ar, F_ZERO) && ar->min > ar->prec)
		ar->prec = ar->min;
	if (flag(ar, F_HASH) && v != 0 && ar->prec <= ln)
		ar->prec++;
	if (!(tab = padded_ulltoa_octal(v, ar->prec, ar->min, flag(ar, F_MINS))))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*size_uoctal(t_printf *const data, t_arg *const ar)
{
	size_t		v;
	char		*tab;
	int			ln;

	v = (size_t)ar->val.i;
	if ((ln = ft_unsignedlen_base(v, "01234567")) > ar->prec && (v || ar->prec))
		ar->prec = ln;
	if (flag(ar, F_ZERO) && ar->min > ar->prec)
		ar->prec = ar->min;
	if (flag(ar, F_HASH) && v != 0 && ar->prec <= ln)
		ar->prec++;
	if (!(tab = padded_ulltoa_octal(v, ar->prec, ar->min, flag(ar, F_MINS))))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*ssize_uoctal(t_printf *const data, t_arg *const ar)
{
	size_t		v;
	char		*tab;
	int			ln;

	v = (size_t)ar->val.i;
	if ((ln = ft_unsignedlen_base(v, "01234567")) > ar->prec && (v || ar->prec))
		ar->prec = ln;
	if (flag(ar, F_ZERO) && ar->min > ar->prec)
		ar->prec = ar->min;
	if (flag(ar, F_HASH) && v != 0 && ar->prec <= ln)
		ar->prec++;
	if (!(tab = padded_ulltoa_octal(v, ar->prec, ar->min, flag(ar, F_MINS))))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*ptrdiff_uoctal(t_printf *const data, t_arg *const ar)
{
	ptrdiff_t	v;
	char		*tab;
	int			ln;

	v = (ptrdiff_t)ar->val.i;
	if ((ln = ft_unsignedlen_base(v, "01234567")) > ar->prec && (v || ar->prec))
		ar->prec = ln;
	if (flag(ar, F_ZERO) && ar->min > ar->prec)
		ar->prec = ar->min;
	if (flag(ar, F_HASH) && v != 0 && ar->prec <= ln)
		ar->prec++;
	if (!(tab = padded_ulltoa_octal(v, ar->prec, ar->min, flag(ar, F_MINS))))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*quad_uoctal(t_printf *const data, t_arg *const ar)
{
	t_uquad		v;
	char		*tab;
	int			ln;

	v = (t_uquad)ar->val.i;
	if ((ln = ft_unsignedlen_base(v, "01234567")) > ar->prec && (v || ar->prec))
		ar->prec = ln;
	if (flag(ar, F_ZERO) && ar->min > ar->prec)
		ar->prec = ar->min;
	if (flag(ar, F_HASH) && v != 0 && ar->prec <= ln)
		ar->prec++;
	if (!(tab = padded_ulltoa_octal(v, ar->prec, ar->min, flag(ar, F_MINS))))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
