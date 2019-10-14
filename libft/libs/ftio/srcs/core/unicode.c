/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:02:45 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 08:30:35 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio/ft_types.h"
#include "ftlib.h"

size_t					ft_wchar_len(const wchar_t chr)
{
	size_t				l;

	l = 1;
	if (chr >= 0x80)
		l++;
	if (chr >= 0x800)
		l++;
	if (chr >= 0x10000)
		l++;
	return (l);
}

size_t					ft_wstrlen(const wchar_t *wstr)
{
	register wchar_t	*s;
	register size_t		l;

	l = 0;
	s = (wchar_t *)wstr;
	while (*s)
	{
		l += ft_wchar_len(*s);
		s++;
	}
	return (l);
}

size_t					wchartochars(char *dst, wchar_t c)
{
	char				u[4];
	size_t				len;

	len = 1;
	ft_bzero(u, 4);
	if (c > 0)
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
	ft_memcpy(dst, u + (4 - len), len);
	return (len);
}

char					*ft_wstrtostr(char *dst, const wchar_t *src)
{
	size_t				l;
	char				*d;

	l = 0;
	d = (char *)dst;
	while (!l || *src)
	{
		if ((l = ft_wchar_len(*src)) > ft_strlen(d))
		{
			ft_bzero(d, ft_strlen(d));
			return (d);
		}
		wchartochars(d, *src);
		d += l;
		src++;
	}
	return (dst);
}
