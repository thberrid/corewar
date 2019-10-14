/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 00:01:34 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/29 00:02:14 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ftlib.h"

size_t	add_digit(char **buffer, const size_t l, const char c)
{
	size_t		i;
	size_t		nl;
	char		*new;

	if (!buffer)
		return (0);
	i = l ? l : 32;
	nl = *buffer ? ft_strlen(*buffer) : 0;
	if (nl + 1 >= l)
	{
		i <<= 1;
		if (!(new = ft_memalloc(i)))
			return (0);
		ft_memcpy(new, *buffer, nl);
		free(*buffer);
		*buffer = new;
	}
	(*buffer)[nl] = c;
	(*buffer)[nl + 1] = 0;
	return (i);
}
