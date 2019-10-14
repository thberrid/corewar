/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:29:47 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/15 16:47:46 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

char				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	a;
	unsigned char	b;

	while (*s1 && *s1 == *s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	a = *s1;
	b = *s2;
	if (n)
		return (a - b);
	return (0);
}
