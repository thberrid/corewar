/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <smoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 06:34:03 by smoreno-          #+#    #+#             */
/*   Updated: 2019/10/30 16:39:29 by baurens          ###   ########.fr       */
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
	int		rethd;
	int		ret;
	int		retinst;

	rethd = 0;
	if ((fd = open(path, O_RDONLY)) <= 0)
		return (0);
	while ((ret = gnl(fd, &line)) > 0)
	{
		head->line++;
		if (!*line || line[0] == COMMENT_CHAR)
		{
			ft_strdel(&line);
			continue ;
		}
		if (rethd != 3)
		{
			retinst = check_headder(header, line, fd, &rethd);
			if (retinst < -1 && !head->cflag)
			{
				ft_strdel(&line);
				return (retinst);
			}
			else if (retinst < -1)
				ft_fixheader(header);
		}
		else
		{
			if (!ft_strncmp(NAME_CMD_STRING, line, 5)
				|| !ft_strncmp(COMMENT_CMD_STRING, line, 8))
			{
				ft_strdel(&line);
				continue ;
			}
			if (head->cflag)
			{
				if (debug_instruct(line, head) < 0)
					return (-9);
			}
			else
			{
				if ((retinst = check_instruct(line, head)) < 0)
				{
					ft_strdel(&line);
					return (retinst);
				}
			}
		}
		ft_strdel(&line);
	}
	if (head->cflag && !head->head->id)
	{
		default_op(head->head);
		update_progsize(head, head->head);
	}
	if (ret == -1)
		return (0);
	ft_strdel(&line);
	return (1);
}
