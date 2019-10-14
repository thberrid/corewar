/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chtoa_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 08:01:14 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 08:04:07 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

char	chtoa_base(register char *dest, unsigned char v, const char *b)
{
	int		i;
	int		bl;
	char	t[6];
	char	*s;

	i = 0;
	s = dest;
	*t = '0';
	if (dest)
		*dest++ = '\\';
	bl = ft_strlen(b);
	while (v && (t[i++] = b[(v % bl)]))
		v /= bl;
	if (bl == 2 || bl == 16)
		t[i++] = bl == 2 ? 'b' : 'x';
	if (bl != 10)
		t[i++] = '0';
	while (dest && i--)
		*dest++ = t[i];
	if (dest)
		*dest = 0;
	return (dest ? (int)(dest - s) : (i + 1));
}
