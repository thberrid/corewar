/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:59:53 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/02 14:31:36 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio/gnl.h"

char			gnl(const int fd, char **line)
{
	t_gnl_e	*cur;
	int		ret;

	cur = get_gnl_bufer(fd);
	if ((ret = fdline_(cur->fd, line, &cur->sv)) == 0)
		gnl_flush_elem(cur);
	return (ret);
}
