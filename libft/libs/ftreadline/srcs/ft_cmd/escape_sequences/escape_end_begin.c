/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_end_begin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:55:05 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/28 17:56:48 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio/line_editor.h"
#include "ftlib.h"

char	esc_end_key(const int fd, char buf[MAX_CMD + 1], uint32_t *i)
{
	(void)fd;
	*i += ft_strlen(buf + *i);
	return (0);
}

char	esc_begin_key(const int fd, char buf[MAX_CMD + 1], uint32_t *i)
{
	(void)fd;
	(void)buf;
	*i = 0;
	return (0);
}
