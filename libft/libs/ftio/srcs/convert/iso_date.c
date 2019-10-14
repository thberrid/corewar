/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_date.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:45:31 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 01:15:46 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "ftio/ft_types.h"
#include "ftio/ft_core.h"
#include "ftlib.h"

static const char *g_months[] =
{
	"Jan ",
	"Feb ",
	"Mar ",
	"Apr ",
	"May ",
	"Jun ",
	"Jul ",
	"Aug ",
	"Sep ",
	"Oct ",
	"Nov ",
	"Dec ",
	NULL
};

static char		get_time_iso(char str[21], time_t time)
{
	int			j;
	char		*tm;

	j = 0;
	if (!(tm = ctime(&time)))
		return (-1);
	ft_memcpy(str, tm + 20, 4);
	str[4] = '-';
	ft_memcpy(str + 5, tm + 4, 2);
	str[7] = '-';
	ft_memcpy(str + 8, tm + 8, 2);
	str[10] = 'T';
	ft_memcpy(str + 11, tm + 11, 8);
	str[11 + 8] = 'Z';
	while (g_months[j] && ft_strncmp(g_months[j], tm + 4, 3))
		j++;
	if (str[8] == ' ')
		str[8] = '0';
	str[5] = ++j / 10 + '0';
	str[6] = j % 10 + '0';
	return (0);
}

static char		get_time_ls(char str[21], time_t cur_time)
{
	time_t		rest;
	char		*tm;

	if (!(tm = ctime(&cur_time)))
		return (-1);
	ft_memcpy(str, tm + 4, 7);
	ft_memcpy(str + 7, tm + 11, 5);
	if ((rest = (time(NULL) - cur_time)) < 0 || rest >= 15728400)
		ft_memcpy(str + 7, tm + 19, 5);
	return (0);
}

static char		*date(t_printf *data, t_arg *arg)
{
	char		str[21];
	char		*res;
	int			len;
	int			tab_len;

	ft_bzero(str, 21);
	if (flag(arg, F_HASH) && get_time_ls(str, (time_t)arg->val.i))
		return (NULL);
	else if (!flag(arg, F_HASH) && get_time_iso(str, (time_t)arg->val.i))
		return (NULL);
	if ((len = ft_strlen(str)) > arg->prec && arg->prec)
		len = arg->prec;
	if ((tab_len = arg->min) < len)
		tab_len = len;
	if (!(res = malloc(tab_len + 1)))
		return (NULL);
	res[tab_len] = 0;
	ft_memset(res, flag(arg, F_ZERO) ? '0' : ' ', tab_len);
	tab_len -= (flag(arg, F_MINS) ? tab_len : len);
	ft_strncpy(res + tab_len, str, len);
	insert_buffer(data, res, ft_strlen(res));
	free(res);
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, ARG_INT, date},
	{'\0', FALSE, ARG_NON, NULL}
};

char			*convert_iso_date(t_printf *data, t_arg *arg)
{
	int			i;
	int			prec;
	int			min;

	min = arg->min;
	prec = arg->prec;
	i = get_arg_a(data, arg->flag_idx, arg);
	i = (i || (arg->min_idx && get_arg_i(data, arg->min_idx, &min)));
	if (i || (arg->prec_idx && get_arg_i(data, arg->prec_idx, &prec)))
		return (NULL);
	arg->min = (((int)min) < 0 ? 0 : (int)min);
	if ((arg->prec = (((int)prec) < 0 ? 0 : (int)prec))
		|| flag(arg, F_MINS))
		arg->flags &= ~F_ZERO;
	i = 0;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}
