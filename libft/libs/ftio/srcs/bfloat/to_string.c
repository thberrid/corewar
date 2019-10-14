/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 07:28:35 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/30 23:10:43 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ftio/ft_bigfloat.h"
#include "ftlib.h"

char		*bflt_tostr(t_bflt const *const num)
{
	size_t	i;
	char	dec;
	char	*res;

	i = 0;
	if (!num)
		return (NULL);
	if (!(dec = (num->dec != NULL)))
		dec = 2;
	if (!(res = ft_memalloc(num->len + dec + 1)))
		return (NULL);
	res[num->len + dec - 1] = 0;
	while (i < num->len + dec - 1)
	{
		if (i < num->entl)
			res[i] = num->ent[i] + '0';
		else if (i > num->entl)
			res[i] = num->dec ? num->dec[i - num->entl - 1] + '0' : '0';
		else
			res[i] = '.';
		i++;
	}
	return (res);
}

void		print_bflt(t_bflt const *const num)
{
	size_t	i;
	t_digit	c;

	i = 0;
	if (!num)
		return ;
	if (num->neg)
		write(1, "-", 1);
	while (i < num->entl)
	{
		c = num->ent[i++] + '0';
		write(1, &c, 1);
	}
	if (num->decl)
		write(1, ".", 1);
	i = 0;
	while (i < num->decl)
	{
		c = num->dec[i++] + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}
