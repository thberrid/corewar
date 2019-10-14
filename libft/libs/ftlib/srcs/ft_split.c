/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:12:06 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/23 19:29:26 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftlib.h"

static size_t			word_len(const char *str, const char *sep)
{
	register const char	*s;

	s = str;
	while (s && *s && !ft_contains(*s, sep))
		s++;
	return (s - str);
}

char					**ft_split(char const *str, char const *sep)
{
	int					i;
	size_t				len;
	char				**ret;

	i = 0;
	if (!str || !sep || !(len = ft_count_words(str, sep)))
		return (NULL);
	if (!(ret = ft_memalloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (*str)
	{
		while (*str && ft_contains(*str, sep))
			str++;
		if (!(ret[i++] = ft_strmcat(NULL, str, word_len(str, sep))))
		{
			while (i > 0)
				free(ret[--i]);
			free(ret);
		}
		while (*str && !ft_contains(*str, sep))
			str++;
	}
	return (ret);
}
