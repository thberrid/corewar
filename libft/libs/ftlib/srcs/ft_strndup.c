/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 19:07:44 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/28 19:11:12 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "ftlib.h"

char	*ft_strndup(const char *str, size_t len)
{
	size_t	l;
	char	*res;

	if ((l = ft_strlen(str)) > len)
		l = len;
	if (!(res = malloc(l + 1)))
		return (NULL);
	ft_strncpy(res, str, l)[l] = 0;
	return (res);
}
