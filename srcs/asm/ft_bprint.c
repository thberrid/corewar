/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 02:29:35 by thberrid          #+#    #+#             */
/*   Updated: 2019/10/20 07:32:15 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

void	ft_bprint_fd(void *ptr, int octet_len, int fd)
{
	int				i;
	int				j;
	unsigned char 	value;

	i = 0;
	while (i < octet_len)
	{
		value = ((unsigned char *)ptr)[i];
		j = 0;
		while (j < 8)
		{
			ft_putnbr_fd(((value & 1) ? 1 : 0), fd);
			j++;
			if (!(j % 4))
				ft_putchar_fd(' ', fd);
			value >>= 1;
		}
		ft_putchar_fd(' ', fd);
		i++;
	}
}

void	ft_bprint_fd_rev(void *ptr, int octet_len, int fd)
{
	int				i;
	int				j;
	unsigned char 	value;

	i = 0;
	while (i < octet_len)
	{
		value = ((unsigned char *)ptr)[octet_len - i - 1];
		j = 8;
		while (j)
		{
			ft_putnbr_fd((((value >> (j - 1)) & 1) ? 1 : 0), fd);
			j--;
		}
		i++;
	}
}
