/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 03:20:13 by thberrid          #+#    #+#             */
/*   Updated: 2019/11/09 03:20:21 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_or_debug(char *line, t_instruct_head *head)
{
	int		retinst;

	if (head->cflag)
	{
		if (debug_instruct(line, head) < 0)
			return (-9);
	}
	else
	{
		if ((retinst = check_instruct(line, head)) < 0)
			return (retinst);
	}
	return (1);
}

int		no_empty_cor(t_instruct_head *head, char *line)
{
	if (head->cflag && !head->head->id)
	{
		if (default_op(head->head) < 0)
		{
			ft_strdel(&line);
			return (-9);
		}
		update_progsize(head, head->head);
	}
	return (1);
}

int		skip_command(char *line, int fd)
{

	while (ft_isspace(*line))
		line++;
	if (!ft_strncmp(NAME_CMD_STRING, line, 5)
		|| !ft_strncmp(COMMENT_CMD_STRING, line, 8))
	{
		if (!ft_contains('"', line))
			return (0);
		if (ft_strcountchar(line, '"') == 2)
		{	
			ft_strdel(&line);
			return (1);
		}
		ft_strdel(&line);
		while (sgnl(fd, &line) > 0)
		{
			if (ft_contains('"', line))
			{	
				ft_strdel(&line);
				return (1);
			}
			ft_strdel(&line);
		}
	}
	return (3);
}

int		return_or_fix(t_instruct_head *hd, t_header *header, int r, char **line)
{
	if (r < -1 && !hd->cflag)
	{
		ft_strdel(line);
		return (r);
	}
	else if (r < -1)
		ft_fixheader(header);
	return (1);
}

int		whilegnl(t_instruct_head *head, char **line, t_header *header, int fd)
{
	int		retrn;
	int		retinst;
	int		rethd;

	rethd = 0;
	while ((retrn = sgnl(fd, line)) > 0)
	{
		head->line++;
		if (!(rethd & NAME_DONE) || !(rethd & COMMENT_DONE))
		{
			retinst = check_headder(header, *line, fd, &rethd);
			if (return_or_fix(head, header, retinst, line) < -1)
				return (retinst);
		}
		else
		{
			if ((retinst = skip_command(*line, fd)) == 0)
				break ;
			else if (retinst == 1)
				continue ;
			if ((retinst = check_or_debug(*line, head)) < 0)
				return (retinst);
		}
		ft_strdel(line);
	}
	return (retrn);
}
