/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:12:42 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/11 21:48:57 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftio/ft_types.h"
#include "ftlib.h"

char		*insert_buffer(t_printf *const data, const char *str, size_t len)
{
	char	*res;

	if (!len)
		return (data->buf);
	if (!data || !str || !(res = ft_memalloc(data->len + len + 1)))
		return (NULL);
	ft_memcpy(res, data->buf, data->len);
	ft_memcpy(res + data->len, str, len);
	data->len += len;
	free(data->buf);
	data->buf = res;
	return (res);
}
