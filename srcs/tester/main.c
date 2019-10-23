/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 09:40:35 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/23 19:15:06 by abaurens         ###   ########.fr       */
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

static void	gen_test_rec(const t_op *op, t_tst *t, int d, int *n)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if ((op->args[d] & g_args[i]))
		{
			t[*n].a[d] = i + 1;
			if (d + 1 < op->arg_cnt)
				gen_test_rec(op, t, d + 1, n);
			else
			{
				ft_memcpy(t[*n + 1].a, t[*n].a, sizeof(t->a));
				++(*n);
			}
		}
		++i;
	}
}

static void	gen_test_files(const char *dir, const t_op *op)
{
	int		i;
	int		j;
	int		fcnt;
	t_tst	tab[27];

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
		j = 0;
		ft_printf("%2d: {%d, %d, %d, %d}\n", i,
		tab[i].a[0], tab[i].a[1], tab[i].a[2], tab[i].a[3]);
		while (j < TEST_PER_CASES)
			gen_file(dir, op, (i * TEST_PER_CASES) + ++j, tab + i);
		++i;
	}
}

int			main(int ac, char **av)
{
	const t_op	*cur;
	char		testnm[25];

	if (ac != 2)
		return (1);
	srand(getpid() ^ getppid() ^ time(NULL));
	cur = g_op_tab;
	while (cur->name && !ft_strequ(cur->name, av[1]))
		++cur;
	if (!cur->name)
		return (1);
	ft_sprintf(testnm, "%s/%s", TEST_DIR, cur->name);
	mkdir(TEST_DIR, 0755);
	mkdir(testnm, 0755);
	gen_test_files(testnm, cur);
	return (0);
}
