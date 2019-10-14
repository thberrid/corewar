/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 00:43:03 by abaurens          #+#    #+#             */
/*   Updated: 2019/07/04 02:25:20 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftio.h"

void		ft_putstr_fd(char const *s, int fd)
{
	size_t	l;

	l = 0;
	while (s && s[l])
		l++;
	if (s && l)
		write(fd, s, l);
}
