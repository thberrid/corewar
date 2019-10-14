/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_len.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:40:26 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 02:11:49 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftio/ft_core.h"
#include "ftio/ft_types.h"
#include "ftlib.h"

char				*short_short_binary(t_printf *const data, t_arg *const arg)
{
	unsigned char	v;
	char			*tab;
	int				len;

	v = (unsigned char)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "01")) > arg->prec && (v || arg->prec))
		arg->prec = len;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (flag(arg, F_HASH) && v != 0 && arg->prec < (len + 2))
		arg->prec += ((len + 2) - arg->prec);
	if (!(tab = padded_ulltoa_bin(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'b';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*short_binary(t_printf *const data, t_arg *const arg)
{
	unsigned short	v;
	char			*tab;
	int				len;

	v = (unsigned short int)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "01")) > arg->prec && (v || arg->prec))
		arg->prec = len;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (flag(arg, F_HASH) && v != 0 && arg->prec < (len + 2))
		arg->prec += ((len + 2) - arg->prec);
	if (!(tab = padded_ulltoa_bin(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'b';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*long_binary(t_printf *const data, t_arg *const arg)
{
	unsigned long	v;
	char			*tab;
	int				len;

	v = (unsigned long int)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "01")) > arg->prec && (v || arg->prec))
		arg->prec = len;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (flag(arg, F_HASH) && v != 0 && arg->prec < (len + 2))
		arg->prec += ((len + 2) - arg->prec);
	if (!(tab = padded_ulltoa_bin(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'b';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*long_long_binary(t_printf *const data, t_arg *const arg)
{
	t_ull	v;
	char	*tab;
	int		len;

	v = (t_ull)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "01")) > arg->prec && (v || arg->prec))
		arg->prec = len;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (flag(arg, F_HASH) && v != 0 && arg->prec < (len + 2))
		arg->prec += ((len + 2) - arg->prec);
	if (!(tab = padded_ulltoa_bin(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'b';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
