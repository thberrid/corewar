/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:31:12 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/14 18:31:20 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftio.h"

int		ft_print_error(const char *str, ...)
{
	va_list	ap;

	va_start(ap, str);
	ft_dprintf(2, "%serror%s: ", "\33[31m", "\33[0m");
	ft_vdprintf(2, str, ap);
	va_end(ap);
	return (1);
}
