/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 01:35:31 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/03 03:27:42 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftlib.h"
#include "vm.h"

void	flush_buffer(const int fd)
{
	write(fd, g_buff, g_pos);
	g_pos = 0;
}

void	corewar_putchar(const int fd, char c)
{
	g_buff[g_pos] = c;
	if (++g_pos >= OUT_BUF_SIZE)
		flush_buffer(fd);
}

void	corewar_write(const int fd, const char *buff, int size)
{
	int	s;

	while ((s = size) > 0)
	{
		if (g_pos + s >= OUT_BUF_SIZE)
			s = OUT_BUF_SIZE - g_pos;
		if (s < BUFF_TRESHOLD)
		{
			flush_buffer(fd);
			continue ;
		}
		ft_memcpy(g_buff + g_pos, buff, s);
		g_pos += s;
		buff += s;
		size -= s;
		if (g_pos >= OUT_BUF_SIZE)
			flush_buffer(fd);
	}
}

void	corewar_putstr(const int fd, const char *buff)
{
	int	s;

	while ((s = ft_strlen(buff)) > 0)
	{
		if (g_pos + s >= OUT_BUF_SIZE)
			s = OUT_BUF_SIZE - g_pos;
		if (s < BUFF_TRESHOLD)
		{
			flush_buffer(fd);
			continue ;
		}
		ft_memcpy(g_buff + g_pos, buff, s);
		g_pos += s;
		buff += s;
		if (g_pos >= OUT_BUF_SIZE)
			flush_buffer(fd);
	}
}
