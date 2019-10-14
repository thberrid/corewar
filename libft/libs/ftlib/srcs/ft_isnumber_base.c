/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 03:13:29 by abaurens          #+#    #+#             */
/*   Updated: 2019/07/18 03:22:19 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

/*
**	Checks if the strings pointer by str is a number expressed in the given base
**	A string is considered to be a number if, and only if, the base is valid
**	and str is part of this regex's language "^[+-]*[base]+$"
*/

char	ft_isnumber_base(register const char *str, const char *base)
{
	if (!base || !ft_isbase(base))
		return (0);
	while (str && (*str == '+' || *str == '-'))
		str++;
	if (str && !*str)
		return (0);
	while (str && ft_contains(*str, base))
		str++;
	return (*str == 0);
}
