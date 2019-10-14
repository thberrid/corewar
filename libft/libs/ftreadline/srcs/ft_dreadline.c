/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dreadline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 21:41:43 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/02 15:39:08 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "ftio/line_editor.h"
#include "ftlib.h"
#include "ftio.h"

#ifndef FT_DISABLE_TERMCAPS

int		init_term(t_term *term)
{
	if (tcgetattr(0, term) == -1)
		return (1);
	term->c_lflag &= ~ICANON;
	term->c_lflag &= ~ECHO;
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSAFLUSH, term) == -1)
		return (1);
	write(1, "\033[?1l", 5);
	return (0);
}

int		reset_term(t_term *term)
{
	if (tcgetattr(0, term) == -1)
		return (-1);
	term->c_lflag = ICANON | ECHO;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (-1);
	return (0);
}

char	*ft_dreadline(const int fd, const char *prompt)
{
	t_term	term;
	char	*res;

	if (isatty(fd) && !init_term(&term))
		res = ft_readline_(fd, prompt);
	else if ((res = NULL) || gnl(fd, &res) < 0)
	{
		gnl_clear();
		ft_print_error("ft_readline: unable to read fd %d\n", fd);
	}
	reset_term(&term);
	return (res);
}

#else

char	*ft_dreadline(const int fd, const char *prompt)
{
	char		c;
	char		*res;

	c = 1;
	while (c)
	{
		res = NULL;
		write(1, prompt, ft_strlen(prompt));
		if ((c = gnl(fd, &res)) < 0)
		{
			gnl_clear();
			ft_print_error("ft_readline: unable to read fd %d\n", fd);
			ft_memdel(&res);
		}
	}
	return (res);
}

#endif
