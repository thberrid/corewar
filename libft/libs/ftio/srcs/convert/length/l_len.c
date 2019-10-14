/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_len.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:30:32 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 02:11:59 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio/ft_types.h"

char			*short_short_length(t_printf *const data, t_arg *const arg)
{
	signed char	*v;

	v = (signed char *)arg->val.p;
	*v = data->len;
	return (data->buf);
}

char			*short_length(t_printf *const data, t_arg *const arg)
{
	short int	*v;

	v = (short int *)arg->val.p;
	*v = data->len;
	return (data->buf);
}

char			*long_length(t_printf *const data, t_arg *const arg)
{
	long int	*v;

	v = (long int *)arg->val.p;
	*v = data->len;
	return (data->buf);
}

char			*long_long_length(t_printf *const data, t_arg *const arg)
{
	t_ll	*v;

	v = (t_ll *)arg->val.p;
	*v = data->len;
	return (data->buf);
}
