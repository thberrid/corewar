/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 00:36:27 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 08:30:14 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "ftlib.h"

void	ft_putchar(wchar_t c)
{
	char	u[4];
	size_t	len;

	len = 1;
	ft_bzero(u, 4);
	u[3] = (c & 0x7F);
	if (c >= 0x80 && len++)
	{
		u[3] = 0x80 | (c & 0x3F);
		u[2] = 0xC0 | ((c >> 6) & 0x1F);
		if (c >= 0x800 && len++)
		{
			u[2] = 0x80 | ((c >> 6) & 0x3F);
			u[1] = 0xE0 | ((c >> 12) & 0x0F);
			if (c >= 0x10000 && len++)
			{
				u[1] = 0x80 | ((c >> 12) & 0x3F);
				u[0] = 0xF0 | ((c >> 18) & 0x07);
			}
		}
	}
	write(1, u + (4 - len), len);
}
