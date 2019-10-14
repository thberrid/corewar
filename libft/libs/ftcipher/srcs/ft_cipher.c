/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cipher.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:11:35 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/15 01:10:24 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftcipher/cipher_core.h"
#include "ftcipher.h"
#include "ftlib.h"

void	*ft_cipher(const void *src, const size_t size)
{
	size_t			i;
	uint8_t			*key;
	uint8_t			*res;
	const uint8_t	*s;

	if (!src || !size || !(key = ft_memalloc(size)))
		return (NULL);
	i = 0;
	s = src;
	while (i < size)
	{
		key[i] = s[i] ^ MAGIC;
		i++;
	}
	rkey(key, size);
	res = interlace_x(key, s, size);
	free(key);
	return (res);
}

uint8_t	ft_decipher(const void *data, void *dest, size_t size)
{
	size_t	i;
	uint8_t	*res;
	uint8_t	*key;

	i = 0;
	res = NULL;
	key = NULL;
	uninterlace_x(data, &key, &res, size);
	size /= 2;
	rkey(key, size);
	while (i < size)
	{
		if (key[i] != (res[i] ^ MAGIC))
		{
			free(key);
			free(res);
			return (0);
		}
		i++;
	}
	if (dest)
		ft_memcpy(dest, res, size);
	free(key);
	free(res);
	return (1);
}
