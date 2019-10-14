/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idxof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:50:48 by abaurens          #+#    #+#             */
/*   Updated: 2019/06/12 11:38:41 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

size_t	ft_idxof(const char c, register const char *str)
{
	register const char *s;

	s = str;
	while (s && *s && *s != c)
		++s;
	return (s - str);
}
