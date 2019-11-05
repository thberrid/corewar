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


int		get_namecom(char *header, char *line, int fd, char n_or_c)
{
	int	i;
	int		rest;

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
	{
		if (*(line + 1) == '\0')
			return (1);
		else
			return (-1);
	}
	if (gnl(fd,&line) > 0)
	{
		header[i] = '\n';
		return (get_namecom(&header[++i], line, fd, n_or_c));
	}
	return (-1);
}

int		check_headder(t_header *header, char *line, int fd, int *rethd)
{
	int		i;
	int 	ret;
	if (ft_strlen(line) < 5)
		return (0);
	if (!ft_strncmp(line, NAME_CMD_STRING, 5))
	{	
		*rethd |= 1;
		if (!ft_contains('"', line))
		return (-2);
	}
	if (!ft_strncmp(line, COMMENT_CMD_STRING, 8))
	{	
		*rethd |= 2;
		if (!ft_contains('"', line))
		return (-2);
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
			if ((ret = get_namecom(header->prog_name, line, fd, 1)) < 0)
				return (ret);
		}
		else if (*line == '"' && i == 8)
		{
			line++;
			if ((ret = get_namecom(header->comment, line, fd, 0)) < 0)
				return (ret);
		}
	//	if (header->prog_name[0] && header->comment[0])
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
//	int		count;

	rethd = 0;
	//count = 0;
	if((fd = open(path, O_RDONLY)) <= 0)
		return (0);
	while ((ret = gnl(fd, &line)) > 0)
	{	
		head->line++;
		if (!*line)
		{
			ft_strdel(&line);
			continue ;
		}
		if (line[0] == COMMENT_CHAR)
			continue ;
		if (rethd != 3)
		{
			retinst = check_headder(header, line, fd, &rethd);
			if (retinst < -1 && !head->cflag)
				return (retinst);
			else if (retinst < -1)
				ft_fixheader(header);
		}
		else
		{
			if (!ft_strncmp(NAME_CMD_STRING, line, 5) || !ft_strncmp(COMMENT_CMD_STRING, line, 8))
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
				if ((retinst = check_instruct(line, head)) < 0)
					return (retinst);
		}
		ft_strdel(&line);
	}
	if (ret == -1)
		return (0);
	ft_strdel(&line);
	return (1);
}
