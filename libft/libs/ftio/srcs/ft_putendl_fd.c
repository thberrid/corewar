/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 00:44:23 by abaurens          #+#    #+#             */
/*   Updated: 2019/07/04 02:25:04 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftio.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t	l;

	l = 0;
	while (s && s[l])
		l++;
	if (s && l > 0)
		write(fd, s, l);
	write(fd, "\n", 1);
}
