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

#include <fcntl.h>
#include "ftlib.h"
#include "ftio.h"
#include "asm.h"


int		get_namecom(char *header, char *line, int fd)
{
	int	i;

	i = 0;
	while (*line && *line != '"')
	{
		header[i] = *line;
		line++;
		i++;
	}
	if (*line == '"')
	{
		if (*(line + 1) == '\0')
			return (1);
		else
			return (0);
	}
	if (gnl(fd,&line) > 0)
	{
		header[i] = '\n';
		return (get_namecom(&header[++i], line, fd));
	}
	return (0);
}

int		check_headder(t_header *header, char *line, int fd, int *rethd)
{
	int		i;

	if (ft_strlen(line) < 5)
		return (0);
	if (!ft_strncmp(line, NAME_CMD_STRING, 5))
	{	
		*rethd |= 1;
		if (!ft_contains('"', line))
		return (-1);
	}
	if (!ft_strncmp(line, COMMENT_CMD_STRING, 8))
	{	
		*rethd |= 2;
		if (!ft_contains('"', line))
		return (-1);
	}
	i = (ft_strncmp(line, NAME_CMD_STRING, 5) == 0) ? 5 : 0;
	i = (i != 5 && ft_strncmp(line, COMMENT_CMD_STRING, 8) == 0) ? 8 : i;
	if (i)
	{
		line += i;
		while (ft_isspace(*line))
			line++;
		if (*line == '"' && i == 5)
		{
			line++;
			if (!get_namecom(header->prog_name, line, fd))
				return (-1);
		}
		else if (*line == '"' && i == 8)
		{
			line++;
			if (!get_namecom(header->comment, line, fd))
				return (-1);
		}
	//	if (header->prog_name[0] && header->comment[0])
		if (*rethd == 3)
			return (1);
		return (0);
	}
	return (-1);
}

int		ft_read(t_instruct_head *head, char *path, t_header *header)
{
	int		fd;
	char	*line;
	int		rethd;
	int		ret;

	rethd = 0;

	if(!(fd = open(path, O_RDONLY)))
		return (0);
	while ((ret = gnl(fd, &line)) > 0)
	{
		if (!*line)
		{
			ft_strdel(&line);
			continue ;
		}
		if (line[0] == COMMENT_CHAR)
			continue ;
		if (rethd != 3)
		{
			if (check_headder(header, line, fd, &rethd) == -1)
				return (0);
		}
		else
		{
			if (!ft_strncmp(NAME_CMD_STRING, line, 5) || !ft_strncmp(COMMENT_CMD_STRING, line, 8))
			{
				ft_strdel(&line);
				continue ;
			}
			if (check_instruct(line, head) < 0)
				return (0);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}
