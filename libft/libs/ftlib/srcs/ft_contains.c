/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:52:34 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/02 14:19:41 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

char	ft_contains(const char c, register const char *str)
{
	while (str && *str)
		if (c == *str++)
			return (1);
	return (0);
}
