/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padded_ulltoa_octal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:02:00 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 06:20:44 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "ftio/ft_types.h"
#include "ftlib.h"

char	*padded_ulltoa_octal(t_ull nb, const int min_d, const int pad, char r)
{
	int		len;
	int		pad_i;
	char	*ret;
	char	*base;

	r = (r != 0);
	base = "01234567";
	if ((len = ft_unsignedlen_base(nb, base)) < min_d)
		len = min_d;
	if (min_d == 0 && nb == 0)
		len = 0;
	pad_i = (pad > len) ? (pad - len) : 0;
	if (!(ret = (char *)ft_memalloc(pad_i + len + 1)))
		return (NULL);
	ret[pad_i + len] = 0;
	ft_memset(ret + (!r * pad_i), '0', len);
	ft_memset(ret + (r * len), ' ', pad_i);
	if (min_d != 0 || nb != 0)
		ret[(!r * pad_i)] = '0';
	while (nb != 0)
	{
		ret[(!r * pad_i) + --len] = base[nb % 8];
		nb /= 8;
	}
	return (ret);
}
