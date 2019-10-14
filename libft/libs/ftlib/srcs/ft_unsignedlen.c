/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 23:29:54 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/05 11:38:18 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <inttypes.h>

size_t		ft_unsignedlen(uintmax_t nb)
{
	size_t	len;

	len = 1;
	while ((nb /= 10) != 0)
		len++;
	return (len);
}
