/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 08:43:21 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 06:30:35 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ftio/line_editor.h"
#include "ftmath.h"
#include "ftlib.h"
#include "ftio.h"

static void		print_buf(t_cmdline buf, uint32_t i, char last)
{
	write(1, "\033[u", 3);
	write(1, "\033[0J", 4);
	write(1, buf, ft_strlen(buf));
	write(1, "\033[u", 3);
	if (i > 0)
	{
		write(1, "\033[", 2);
		ft_putnbr(i);
		write(1, "C", 1);
	}
	if (last)
		write(1, "\n", 1);
}

static uint32_t	del(t_cmdline buf, uint32_t i)
{
	uint32_t	j;

	if (i <= 0)
		return (0);
	j = i - 1;
	while (buf[j++])
		buf[j - 1] = buf[j];
	return (1);
}

static char		insert(const char c, t_cmdline buf, uint32_t i)
{
	if (c == 127)
		return (-del(buf, i));
	if (!ft_isprint(c))
		return (0);
	*((char *)ft_memmove(buf + i + 1, buf + i, ft_strlen(buf + i) + 1) - 1) = c;
	return (1);
}

char			line_editor_reader(const int fd, char **ret)
{
	char		t;
	uint32_t	i;
	t_cmdline	buf;

	i = 0;
	*buf = 0;
	write(1, "\033[s", 3);
	while (1)
	{
		if (read(fd, &t, 1) < 0)
			return (-1);
		if ((t == 4 && *buf == 0) || t == 12)
			return (t);
		if (t == 27)
			esc_sequence(fd, buf, &i);
		else if (t != '\n' && t != 4)
			i += insert(t, buf, i);
		else if (t == '\n')
			break ;
		else
			continue ;
		print_buf(buf, i, 0);
	}
	print_buf((*ret = ft_strdup(buf)), 0, 1);
	return (1);
}

char			*ft_readline_(const int fd, const char *prompt)
{
	char		c;
	char		*res;

	c = 0;
	while (c != 1)
	{
		res = NULL;
		write(1, prompt, ft_strlen(prompt));
		if ((c = line_editor_reader(fd, &res)) < 0)
		{
			ft_print_error("ft_readline: unable to read fd %d\n", fd);
			ft_memdel(&res);
		}
		if (c == 4 && write(1, "\n", 1))
			return (NULL);
		if (c == 12)
			write(1, "\033[0;0H\033[0J", 6 + 4);
	}
	return (res);
}
