/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedlen_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 23:30:48 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/05 11:38:45 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <string.h>
#include "ftlib.h"

size_t		ft_unsignedlen_base(uintmax_t nb, const char *base)
{
	size_t	len;
	size_t	blen;

	len = 1;
	if (!base || !ft_isbase(base))
		return (0);
	blen = ft_strlen(base);
	while ((nb /= blen) != 0)
		len++;
	return (len);
}
