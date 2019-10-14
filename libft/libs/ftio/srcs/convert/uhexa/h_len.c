/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_len.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:56:53 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 02:20:56 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftio/ft_core.h"
#include "ftio/ft_types.h"
#include "ftlib.h"

char				*short_short_hexa(t_printf *const data, t_arg *const arg)
{
	unsigned char	v;
	int				len;
	char			*tab;

	v = (unsigned char)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "0123456789abcdef")) > arg->prec
		&& (v || arg->prec))
		arg->prec = len;
	if (flag(arg, F_HASH) && v != 0)
		arg->prec += 2;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa_hexa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'x';
	if (ft_isupper(arg->conv.c))
		ft_strupcase(tab);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*short_hexa(t_printf *const data, t_arg *const arg)
{
	unsigned short	v;
	int				len;
	char			*tab;

	v = (unsigned short int)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "0123456789abcdef")) > arg->prec
		&& (v || arg->prec))
		arg->prec = len;
	if (flag(arg, F_HASH) && v != 0)
		arg->prec += 2;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa_hexa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'x';
	if (ft_isupper(arg->conv.c))
		ft_strupcase(tab);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*long_hexa(t_printf *const data, t_arg *const arg)
{
	unsigned long	v;
	int				len;
	char			*tab;

	v = (unsigned long int)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "0123456789abcdef")) > arg->prec
		&& (v || arg->prec))
		arg->prec = len;
	if (flag(arg, F_HASH) && v != 0)
		arg->prec += 2;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa_hexa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'x';
	if (ft_isupper(arg->conv.c))
		ft_strupcase(tab);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*long_long_hexa(t_printf *const data, t_arg *const arg)
{
	t_ull	v;
	int		len;
	char	*tab;

	v = (t_ull)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "0123456789abcdef")) > arg->prec
		&& (v || arg->prec))
		arg->prec = len;
	if (flag(arg, F_HASH) && v != 0)
		arg->prec += 2;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa_hexa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'x';
	if (ft_isupper(arg->conv.c))
		ft_strupcase(tab);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
