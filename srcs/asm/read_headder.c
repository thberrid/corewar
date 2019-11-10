/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_headder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 04:33:38 by thberrid          #+#    #+#             */
/*   Updated: 2019/11/10 04:33:41 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		init_headder(char *line, int *rethd)
{
	int	i;
	int	j;

	j = 1;
	while (ft_isspace(*line) && j++)
		line++;
	if (ft_strlen(line) < 5)
		return (0);
	if (!ft_strncmp(line, NAME_CMD_STRING, 5))
	{
		set_rethd(1, rethd);
		if (!ft_contains('"', line))
			return (-2);
	}
	if (!ft_strncmp(line, COMMENT_CMD_STRING, 8))
	{
		set_rethd(0, rethd);
		if (!ft_contains('"', line))
			return (-2);
	}
	i = (ft_strncmp(line, NAME_CMD_STRING, 5) == 0) ? 5 : 0;
	i = (i != 5 && ft_strncmp(line, COMMENT_CMD_STRING, 8) == 0) ? 8 : i;
	return (i + j);
}
