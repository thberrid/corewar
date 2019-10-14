/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:02:33 by abaurens          #+#    #+#             */
/*   Updated: 2019/07/30 18:24:06 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftio.h"

int	ft_debugf(int fd, char bool, const char *str, ...)
{
	int		res;
	va_list	lst;

	if (!bool)
		return (0);
	ft_dprintf(fd, "[DEBUG]");
	va_start(lst, str);
	res = ft_vdprintf(fd, str, lst);
	va_end(lst);
	return (res);
}
