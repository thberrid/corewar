/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_len.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:29:23 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 02:11:33 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftio/ft_core.h"
#include "ftio/ft_types.h"
#include "ftlib.h"

char			*short_short_uoctal(t_printf *const data, t_arg *const ar)
{
	unsigned char	v;
	char			*tab;
	int				ln;

	v = (unsigned char)ar->val.i;
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

char			*short_uoctal(t_printf *const data, t_arg *const ar)
{
	unsigned short	v;
	char			*tab;
	int				ln;

	v = (unsigned short int)ar->val.i;
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

char			*long_uoctal(t_printf *const data, t_arg *const ar)
{
	unsigned long	v;
	char			*tab;
	int				ln;

	v = (unsigned long int)ar->val.i;
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

char			*long_long_uoctal(t_printf *const data, t_arg *const ar)
{
	t_ull	v;
	char	*tab;
	int		ln;

	v = (t_ull)ar->val.i;
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
