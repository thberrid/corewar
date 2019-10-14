/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:14:45 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/30 23:23:49 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftio.h"

int		ft_vsprintf(char *str, const char *format, va_list ap)
{
	return (ft_vsnprintf(str, 2147483648u, format, ap));
}

int		ft_sprintf(char *str, const char *format, ...)
{
	int		l;
	va_list	lst;

	va_start(lst, format);
	l = ft_vsprintf(str, format, lst);
	va_end(lst);
	return (l);
}
