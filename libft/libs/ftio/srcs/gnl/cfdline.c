/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfdline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:19:40 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/02 15:24:39 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ftio/gnl.h"
#include "ftlib.h"

char		cfdline_(const int fd, char **line, char **save, const char *crset)
{
	int		n;
	size_t	l;
	char	*tmp;
	char	buff[GNL_BUF + 1];

	while ((l = ft_idxof('\n', *save)) == ft_idxof(0, *save))
	{
		if ((n = read(fd, buff, GNL_BUF)) < 0 || !gnl_rd_check_(buff, n, crset))
			return (-1);
		if (n == 0)
			break ;
		buff[n] = 0;
		if (!(tmp = gnl_cat_(*save, buff, -1)))
			return (-1);
		free(*save);
		*save = tmp;
	}
	tmp = *save;
	if (tmp && !(*line = gnl_cat_(NULL, tmp, l)))
		return (-1);
	n = (tmp && (!tmp[l] || (tmp[l] == '\n' && ++l)));
	*save = ((tmp && tmp[l]) ? gnl_cat_(0x0, tmp + l, -1) : 0x0);
	free(tmp);
	return (n != 0 || *save != NULL);
}
