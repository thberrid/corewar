/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 03:13:29 by abaurens          #+#    #+#             */
/*   Updated: 2019/07/18 03:19:47 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Checks if the strings pointer by str is a number.
**	A string is considered to be a number if, and only if,
**	it's part of this regex's language "^[+-]*[0-9]+$"
*/

char	ft_isnumber(register const char *str)
{
	while (str && (*str == '+' || *str == '-'))
		str++;
	if (str && !*str)
		return (0);
	while (str && *str >= '0' && *str <= '9')
		str++;
	return (*str == 0);
}
