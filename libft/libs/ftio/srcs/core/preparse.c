/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:43:26 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/15 18:57:14 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio/converter.h"
#include "ftio/ft_core.h"
#include "ftlib.h"

static size_t	step_dolar(const char *frm)
{
	size_t		len;

	len = 0;
	while (frm[len] >= '0' && frm[len] <= '9')
		len++;
	if (frm[len++] != '$')
		return (0);
	return (len);
}

static char		is_conv(char c)
{
	int			i;

	i = 0;
	while (g_converters[i].c && g_converters[i].c != c)
		i++;
	return (g_converters[i].c == c && g_converters[i].w_arg == TRUE);
}

static size_t	step_width_prec(const char *frm, size_t *args)
{
	size_t		len;

	len = step_dolar(frm);
	if ((frm[len] != '*' && ++(*args)) || !++len)
		while (frm[len] >= '0' && frm[len] <= '9')
			len++;
	else
		len += step_dolar(frm);
	if (frm[len] == '.' && ++len)
	{
		if ((frm[len] != '*' && ++(*args)) || !++len)
			while (frm[len] >= '0' && frm[len] <= '9')
				len++;
		else
			len += step_dolar(frm);
	}
	return (len);
}

size_t			count_args(const char *frm)
{
	size_t		args;

	args = 0;
	while (*frm)
	{
		frm += ft_idxof('%', frm);
		if (!*frm || !frm++)
			continue ;
		while (ft_contains(*frm, FLAGS_V))
			frm++;
		frm += step_width_prec(frm, &args);
		while (ft_contains(*frm, LEN_MD))
			frm++;
		if (is_conv(*frm) && ++frm)
			args++;
	}
	return (args);
}
