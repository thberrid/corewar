/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:18:44 by abaurens          #+#    #+#             */
/*   Updated: 2019/07/04 02:34:02 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftio/converter.h"
#include "ftio/ft_types.h"
#include "ftio/ft_core.h"
#include "ftlib.h"

static char		*long_hexa_ptr(t_printf *const data, t_arg *const arg)
{
	intptr_t	v;
	int			len;
	char		*tab;

	v = (intptr_t)arg->val.p;
	if ((len = ft_unsignedlen_base(v, "0123456789abcdef")) > arg->prec
		&& (v || arg->prec))
		arg->prec = len;
	arg->prec += 2;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa_hexa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	tab[ft_idxof('0', tab) + 1] = 'x';
	if (ft_isupper(arg->conv.c))
		ft_strupcase(tab);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*convert_pointer(t_printf *data, t_arg *arg)
{
	int			i;
	int			min;
	int			prec;

	min = arg->min;
	prec = arg->prec;
	i = get_arg_a(data, arg->flag_idx, arg);
	i = (i || (arg->min_idx && get_arg_i(data, arg->min_idx, &min)));
	if (i || (arg->prec_idx && get_arg_i(data, arg->prec_idx, &prec)))
		return (NULL);
	arg->prec = prec;
	if ((arg->min = min) < 0 && (arg->flags |= F_MINS))
		arg->min = -min;
	if (prec >= 0 || flag(arg, F_MINS))
		arg->flags &= ~F_ZERO;
	return (long_hexa_ptr(data, arg));
}
