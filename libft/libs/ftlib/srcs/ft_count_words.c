/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 19:27:22 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/23 19:29:20 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ftlib.h"

size_t			ft_count_words(const char *str, const char *sep)
{
	register size_t		i;

	i = 0;
	while (str && *str)
	{
		if (!ft_contains(*str, sep) && (!str[1] || ft_contains(str[1], sep)))
			i++;
		str++;
	}
	return (i);
}
