/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:18:32 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/16 12:01:52 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"
#include <unistd.h>
#include <stdlib.h>

static void	set_tab(size_t tb[256], const char *needle, register const size_t l)
{
	register size_t	i;

	i = 0;
	while (i < 255)
		tb[i++] = l;
	i = 0;
	while (i < (l - 1))
	{
		tb[(int)needle[i]] = l - 1 - i;
		++i;
	}
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	register size_t			i;
	register size_t			hl;
	register const size_t	nl = ft_strlen(needle);
	size_t					tab[256];

	if (!*needle)
		return ((char *)haystack);
	set_tab(tab, needle, nl);
	hl = ft_strlen(haystack);
	while (hl >= nl)
	{
		i = nl - 1;
		while (haystack[i] == needle[i])
			if (i-- == 0)
				return ((char *)haystack);
		hl -= tab[(int)haystack[nl - 1]];
		haystack += tab[(int)haystack[nl - 1]];
	}
	return (NULL);
}

/*
**	static char		*ft_strstr2(const char *haystack, const char *needle)
**	{
**		int	i;
**
**		while (*haystack)
**		{
**			i = 0;
**			while (needle[i] && haystack[i] && needle[i] == haystack[i])
**				i++;
**			if (needle[i] == 0)
**				return ((char *)haystack);
**			haystack++;
**		}
**		if (!*needle)
**			return ((char *)haystack);
**		return (NULL);
**	}
*/
