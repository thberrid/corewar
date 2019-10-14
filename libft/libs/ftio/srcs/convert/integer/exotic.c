/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exotic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:22:40 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 06:19:30 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftio/ft_core.h"
#include "ftio/ft_types.h"
#include "ftlib.h"

char			*intmax_integer(t_printf *const data, t_arg *const ar)
{
	intmax_t	v;
	size_t		l;
	char		*tab;

	v = (intmax_t)ar->val.i;
	if ((long)(l = (ft_numlen(v) - (v < 0))) > ar->prec && (v || ar->prec))
		ar->prec = l;
	if (flag(ar, (F_PLUS | F_SPAC)) && v >= 0 && ++l)
		ar->prec++;
	if ((v != 0 || ar->prec != 0) && (l + (v < 0)) > (size_t)ar->min)
		ar->min = l + (v < 0);
	if (flag(ar, F_ZERO) && ar->prec < ar->min)
		ar->prec = ar->min - (v < 0);
	if (!(tab = padded_lltoa(v, ar->prec, ar->min, flag(ar, F_MINS))))
		return (NULL);
	if (flag(ar, (F_PLUS | F_SPAC)) && (intmax_t)ar->val.i >= 0)
		tab[ft_idxof('0', tab)] = flag(ar, F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*size_integer(t_printf *const data, t_arg *const ar)
{
	ssize_t		v;
	size_t		l;
	char		*tab;

	v = (ssize_t)ar->val.i;
	if ((long)(l = (ft_numlen(v) - (v < 0))) > ar->prec && (v || ar->prec))
		ar->prec = l;
	if (flag(ar, (F_PLUS | F_SPAC)) && ++l)
		ar->prec++;
	if ((v != 0 || ar->prec != 0) && (l + (v < 0)) > (size_t)ar->min)
		ar->min = l + (v < 0);
	if (flag(ar, F_ZERO) && ar->prec < ar->min)
		ar->prec = ar->min;
	if (!(tab = padded_lltoa(v, ar->prec, ar->min, flag(ar, F_MINS))))
		return (NULL);
	if (flag(ar, (F_PLUS | F_SPAC)) && (t_ll)v >= 0)
		tab[ft_idxof('0', tab)] = flag(ar, F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*ssize_integer(t_printf *const data, t_arg *const ar)
{
	ssize_t		v;
	size_t		l;
	char		*tab;

	v = (ssize_t)ar->val.i;
	if ((long)(l = (ft_numlen(v) - (v < 0))) > ar->prec && (v || ar->prec))
		ar->prec = l;
	if (flag(ar, (F_PLUS | F_SPAC)) && v >= 0 && ++l)
		ar->prec++;
	if ((v != 0 || ar->prec != 0) && (l + (v < 0)) > (size_t)ar->min)
		ar->min = l + (v < 0);
	if (flag(ar, F_ZERO) && ar->prec < ar->min)
		ar->prec = ar->min - (v < 0);
	if (!(tab = padded_lltoa(v, ar->prec, ar->min, flag(ar, F_MINS))))
		return (NULL);
	if (flag(ar, (F_PLUS | F_SPAC)) && v >= 0)
		tab[ft_idxof('0', tab)] = flag(ar, F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*ptrdiff_integer(t_printf *const data, t_arg *const ar)
{
	ptrdiff_t	v;
	size_t		l;
	char		*tab;

	v = (ptrdiff_t)ar->val.i;
	if ((long)(l = (ft_numlen(v) - (v < 0))) > ar->prec && (v || ar->prec))
		ar->prec = l;
	if (flag(ar, (F_PLUS | F_SPAC)) && v >= 0 && ++l)
		ar->prec++;
	if ((v != 0 || ar->prec != 0) && (l + (v < 0)) > (size_t)ar->min)
		ar->min = l + (v < 0);
	if (flag(ar, F_ZERO) && ar->prec < ar->min)
		ar->prec = ar->min - (v < 0);
	if (!(tab = padded_lltoa(v, ar->prec, ar->min, flag(ar, F_MINS))))
		return (NULL);
	if (flag(ar, (F_PLUS | F_SPAC)) && (ptrdiff_t)ar->val.i >= 0)
		tab[ft_idxof('0', tab)] = flag(ar, F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*quad_integer(t_printf *const data, t_arg *const ar)
{
	t_quad		v;
	size_t		l;
	char		*tab;

	v = (t_quad)ar->val.i;
	if ((long)(l = (ft_numlen(v) - (v < 0))) > ar->prec && (v || ar->prec))
		ar->prec = l;
	if (flag(ar, (F_PLUS | F_SPAC)) && v >= 0 && ++l)
		ar->prec++;
	if ((v != 0 || ar->prec != 0) && (l + (v < 0)) > (size_t)ar->min)
		ar->min = l + (v < 0);
	if (flag(ar, F_ZERO) && ar->prec < ar->min)
		ar->prec = ar->min - (v < 0);
	if (!(tab = padded_lltoa(v, ar->prec, ar->min, flag(ar, F_MINS))))
		return (NULL);
	if (flag(ar, (F_PLUS | F_SPAC)) && (t_quad)ar->val.i >= 0)
		tab[ft_idxof('0', tab)] = flag(ar, F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
