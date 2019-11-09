/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <smoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 06:34:03 by smoreno-          #+#    #+#             */
/*   Updated: 2019/11/08 11:08:14 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_checkline(char *line)
{
	if (*(line + 1) == '\0')
		return (1);
	else
		return (-1);
}

int		get_namecom(char *header, char *line, int fd, char n_or_c)
{
	int		i;
	int		rest;
	int		ret;

	i = 0;
	rest = ft_strlen(header) + ft_strlen(line);
	if (rest > (n_or_c ? PROG_NAME_LENGTH : COMMENT_LENGTH))
		return (n_or_c ? -7 : -8);
	while (*line && *line != '"')
	{
		header[i] = *line;
		line++;
		i++;
	}
	if (*line == '"')
		return (ft_checkline(line));
	if (gnl(fd, &line) > 0)
	{
		header[i] = '\n';
		ret = get_namecom(&header[++i], line, fd, n_or_c);
		ft_strdel(&line);
		return (ret);
	}
	return (-1);
}

int		check_headder(t_header *header, char *line, int fd, int *rethd)
{
	int		i;
	int		ret;

	if ((i = init_headder(line, rethd)) <= 0)
		return (i);
	if (i)
	{
		line += i;
		while (ft_isspace(*line))
			line++;
		if (*line == '"' && i == 5 && line++)
		{
			if ((ret = get_namecom(header->prog_name, line, fd, 1)) < 0)
				return (ret);
		}
		else if (*line == '"' && i == 8 && line++)
		{
			if ((ret = get_namecom(header->comment, line, fd, 0)) < 0)
				return (ret);
		}
		if (*rethd == 3)
			return (1);
		return (0);
	}
	return (-2);
}

void	ft_fixheader(t_header *header)
{
	ft_strcpy(header->prog_name, "default name");
	ft_strcpy(header->comment, "default comment");
}

int		ft_read(t_instruct_head *head, char *path, t_header *header)
{
	int		fd;
	char	*line;
	int		ret;

	if ((fd = open(path, O_RDONLY)) <= 0)
		return (0);
	if ((ret = whilegnl(head, &line, header, fd)) < 0)
		return (ret);
	if (no_empty_cor(head, line) < 0)
		return (-9);
	if (ret == -1)
		return (0);
	ft_strdel(&line);
	return (1);
}
