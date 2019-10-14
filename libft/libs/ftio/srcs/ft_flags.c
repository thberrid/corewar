/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:37:36 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/14 18:27:58 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"
#include "ftlib.h"

static int	f_mask(size_t bits)
{
	return (~((t_flag)(~0) << bits));
}

char		ft_flag(t_flag flags, const char *flagset, const char flag)
{
	int		i;
	char	f_val;

	i = -1;
	f_val = 1;
	while (flagset[++i] && flagset[i] != flag)
		f_val <<= 1;
	f_val &= f_mask(ft_strlen(flagset));
	return (!!(flags & f_val));
}

char		set_flags(t_flag *flags, const char *flagset, const char *arg)
{
	int		i;
	t_flag	mask;
	t_flag	f_val;

	mask = f_mask(ft_strlen(flagset));
	while (arg && *arg)
	{
		i = -1;
		f_val = 1;
		while (flagset[++i] && flagset[i] != *arg)
			f_val <<= 1;
		if ((f_val & ~mask))
			return (*arg);
		*flags |= (f_val & mask);
		arg++;
	}
	return (0);
}
