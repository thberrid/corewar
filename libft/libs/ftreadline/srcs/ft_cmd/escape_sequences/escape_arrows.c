/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_arrow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:27:59 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/28 17:41:48 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio/line_editor.h"

char	esc_up_arrow(const int fd, char buf[MAX_CMD + 1], uint32_t *i)
{
	(void)i;
	(void)fd;
	(void)buf;
	return (0);
}

char	esc_down_arrow(const int fd, char buf[MAX_CMD + 1], uint32_t *i)
{
	(void)i;
	(void)fd;
	(void)buf;
	return (0);
}

char	esc_left_arrow(const int fd, char buf[MAX_CMD + 1], uint32_t *i)
{
	(void)i;
	(void)fd;
	(void)buf;
	if (*i > 0)
		--(*i);
	return (0);
}

char	esc_right_arrow(const int fd, char buf[MAX_CMD + 1], uint32_t *i)
{
	(void)i;
	(void)fd;
	if (buf[*i] != 0)
		++(*i);
	return (0);
}
