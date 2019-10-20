/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 02:29:35 by thberrid          #+#    #+#             */
/*   Updated: 2019/10/20 02:34:10 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

void	ft_bprint(void *ptr, int nbits)
{
	int				i;
	unsigned char 	value;

	i = 0;
	value = *((unsigned char *)ptr);
	while (i < nbits)
	{
		ft_putnbr(((value & 1) ? 1 : 0));
		value >>= 1;
		i += 1;
		if (!(i % 4))
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

