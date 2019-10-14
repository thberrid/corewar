/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_lst_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 02:41:54 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/25 10:17:54 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#if defined(va_copy)

void	save_va_list(va_list *save, va_list ap)
{
	va_copy(*save, ap);
}

#elif defined(__va_copy)

void	save_va_list(va_list *save, va_list ap)
{
	__va_copy(*save, ap);
}

#elif defined(__WATCOMC__)

void	save_va_list(va_list *save, va_list ap)
{
	ft_memcpy(*save, src, sizeof(va_list));
}

#elif defined (_MSC_VER)

void	save_va_list(va_list *save, va_list ap)
{
	*ap_save = ap;
}

#else

# error "Can't find a good way to va_copy for vprintf like functions"

#endif
