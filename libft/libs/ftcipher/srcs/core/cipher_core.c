/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cipher_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:07:13 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/12 16:09:02 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftcipher/cipher_core.h"
#include "ftcipher.h"
#include "ftlib.h"

static t_wrd	reverse_bits(t_wrd b)
{
	b = (b * 0x0202020202UL & 0x010884422010UL) % 1023;
	return (b);
}

void			rkey(t_wrd *ptr, t_len size)
{
	t_len	i;
	t_len	j;
	t_wrd	t;

	i = 0;
	j = size;
	while (i < j)
	{
		j--;
		t = ptr[i];
		ptr[i] = ptr[j];
		ptr[j] = t;
		i++;
	}
	i = 0;
	while (i < size)
	{
		ptr[i] = reverse_bits(ptr[i]);
		i++;
	}
}

t_void			interlace_x(t_coid v1, t_coid v2, t_len size)
{
	t_len	j;
	t_len	i;
	t_crd	*t1;
	t_crd	*t2;
	t_dbl	*res;

	if (!v1 || !v2 || !size || !(res = ft_memalloc(size * sizeof(t_dbl))))
		return (NULL);
	i = 0;
	t1 = v1;
	t2 = v2;
	while (size-- > 0)
	{
		j = 8;
		res[i] = 0;
		while (j-- > 0)
			res[i] = ((res[i] << 1 | (*t1 >> j & 1)) << 1 | (*t2 >> j & 1));
		t1++;
		t2++;
		i++;
	}
	return (res);
}

static void		uninterlace(t_dbl v, t_wrd *s1, t_wrd *s2)
{
	int		i;
	t_wrd	t1;
	t_wrd	t2;

	i = 16;
	t1 = 0;
	t2 = 0;
	if (!s1 && !s2)
		return ;
	while (i-- > 0)
	{
		t1 = (t1 << 1 | (v >> i & 1));
		t2 = (t2 << 1 | (v >> --i & 1));
	}
	if (s1)
		*s1 = t1;
	if (s2)
		*s2 = t2;
}

void			uninterlace_x(t_coid src, t_coid dst1, t_coid dst2, t_len size)
{
	t_len	i;
	t_wrd	*v1;
	t_wrd	*v2;
	t_cbl	*sr;

	sr = src;
	v1 = NULL;
	v2 = NULL;
	size /= 2;
	v1 = ft_memalloc(size);
	if (!v1 || !(v2 = ft_memalloc(size)))
	{
		free(v1);
		free(v2);
		return ;
	}
	i = 0;
	while (size-- > 0 && ++i)
		uninterlace(*sr++, v1 + (i - 1), v2 + (i - 1));
	if (!dst1 || !(*((t_wrd **)dst1) = v1))
		free(v1);
	if (!dst2 || !(*((t_wrd **)dst2) = v2))
		free(v2);
}
