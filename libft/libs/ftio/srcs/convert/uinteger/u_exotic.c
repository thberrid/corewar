/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_exotic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:41:40 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 02:14:15 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftio/ft_core.h"
#include "ftio/ft_types.h"
#include "ftlib.h"

char			*intmax_uinteger(t_printf *const data, t_arg *const arg)
{
	uintmax_t	v;
	char		*tab;

	v = (uintmax_t)arg->val.i;
	if (flag(arg, F_ZERO))
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*size_uinteger(t_printf *const data, t_arg *const arg)
{
	size_t		v;
	char		*tab;

	v = (size_t)arg->val.i;
	if (flag(arg, F_ZERO))
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*ssize_uinteger(t_printf *const data, t_arg *const arg)
{
	size_t		v;
	char		*tab;

	v = (size_t)arg->val.i;
	if (flag(arg, F_ZERO))
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*ptrdiff_uinteger(t_printf *const data, t_arg *const arg)
{
	ptrdiff_t	v;
	char		*tab;

	v = (ptrdiff_t)arg->val.i;
	if (flag(arg, F_ZERO))
		arg->prec = arg->min - (v < 0);
	if (!(tab = padded_ulltoa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*quad_uinteger(t_printf *const data, t_arg *const arg)
{
	t_uquad		v;
	char		*tab;

	v = (t_uquad)arg->val.i;
	if (flag(arg, F_ZERO))
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
