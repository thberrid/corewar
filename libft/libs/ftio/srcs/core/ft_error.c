/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 04:02:07 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 08:24:23 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftio/ft_error_vals.h"
#include "ftio/ft_error.h"
#include "ftmath.h"
#include "ftlib.h"
#include "ftio.h"

char		*ft_strerror(const int errnum)
{
	int		i;
	int		err;
	char	*res;

	i = 0;
	err = errnum;
	while (g_error_table[i].value >= 0 && g_error_table[i].value != errnum)
		i++;
	res = (char *)g_error_table[i].msg;
	if (g_error_table[i].value < 0)
	{
		i = ft_numlen(errnum);
		res[FT_EUNKOWN_LEN] = '-';
		res[FT_EUNKOWN_LEN + i] = 0;
		while (i-- && err)
		{
			res[FT_EUNKOWN_LEN + i] = '0' + ft_abs(err % 10);
			err /= 10;
		}
	}
	return (res);
}

void		ft_perror(const char *str)
{
	int		i;
	int		err;

	err = get_errno();
	if (str)
		ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	i = 0;
	while (g_error_table[i].value >= 0 && g_error_table[i].value != err)
		i++;
	ft_putstr_fd(g_error_table[i].msg, 2);
	write(2, "\n", 1);
}

int			get_errno(void)
{
	if (g_get_errno[0] != NULL)
		return (g_get_errno[0]());
	return (0);
}
