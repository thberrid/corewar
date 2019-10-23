/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 09:40:35 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/23 11:29:43 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_DISABLE_WARNINGS

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "tester.h"
#include "ftlib.h"
#include "op.h"

static int	cnt_cases(unsigned char var)
{
	int		res;

	res = 0;
	while (var)
	{
		res += (var & 1);
		var >>= 1;
	}
	return (res);
}

static const unsigned char	g_args[] = {
	T_REG, T_DIR, T_IND
};

static void	gen_test_rec(const t_op *op, t_tst_case *t, int d, int *n)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if ((op->args[d] & g_args[i]))
		{
			t[*n].argt[d] = i + 1;
			if (d + 1 < op->arg_cnt)
				gen_test_rec(op, t, d + 1, n);
			else
			{
				ft_memcpy(t[*n + 1].argt, t[*n].argt, sizeof(t->argt));
				++(*n);
			}
		}
		++i;
	}
}

static void	gen_test_files(const char *dir, const t_op *op)
{
	int				i;
	int				fcnt;
	t_tst_case		tab[27];

	i = 0;
	ft_bzero(tab, sizeof(tab));
	fcnt = cnt_cases(op->args[0]);
	while (++i < op->arg_cnt)
		fcnt *= cnt_cases(op->args[i]);
	ft_printf("fcnt(%s) = %d\n", op->name, fcnt);
	i = 0;
	gen_test_rec(op, tab, 0, &i);
	i = 0;
	while (i < fcnt)
	{
		ft_printf("%2d: {%d, %d, %d}\n", i,
		tab[i].argt[0], tab[i].argt[1], tab[i].argt[2]);
		gen_file(dir, op, i, tab + i);
		++i;
	}
}

int			main(int ac, char **av)
{
	const t_op	*cur;
	char		testnm[25];

	if (ac != 2)
		return (0);
	srand(getpid() ^ getppid() ^ time(NULL));
	cur = g_op_tab;
	while (cur->name && !ft_strequ(cur->name, av[1]))
		++cur;
	if (!cur->name)
		return (0);
	ft_strcpy(testnm, TEST_DIR "/test_");
	ft_strcat(testnm, cur->name);
	ft_printf("%s\n", testnm);
	mkdir(TEST_DIR, 0755);
	mkdir(testnm, 0755);
	gen_test_files(testnm, cur);
	return (0);
}
