/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_rd_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:21:10 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/02 15:37:27 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ftlib.h"

char	gnl_rd_check_(const char *buf, size_t size, const char *crset)
{
	if (crset)
	{
		while (buf && size--)
			if (!ft_contains(*buf++, crset))
				return (0);
		return (1);
	}
	while (buf && size--)
	{
		if ((*buf < ' ' || *buf > '~') && *buf != '\n' && *buf != '\t')
			return (0);
		buf++;
	}
	return (1);
}
