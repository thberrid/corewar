/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:26:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/07 16:20:59 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_DISABLE_WARNINGS

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "endianes.h"
#include "tester.h"
#include "config.h"
#include "ftlib.h"
#include "ftio.h"
#include "op.h"

static const char	*g_names[] = {
	"none", "reg", "dir", "ind"
};

static uint8_t	gen_ocp(t_tst *p)
{
	return ((p->a[0] << 6)
		| (p->a[1] << 4)
		| (p->a[2] << 2)
		| p->a[3]);
}

static t_byte	gen_arg(t_byte *tmp_mem, const t_op *op, t_byte ocp)
{
	t_ind	ind;
	t_dir	dir;

	if (ocp == REG_CODE)
	{
		*tmp_mem = random_register();
		return (1);
	}
	if (ocp == IND_CODE || op->hdir)
	{
		ind = random_indirect();
		system_to_bin(&ind, IND_SIZE);
		ft_memcpy(tmp_mem, &ind, IND_SIZE);
		return (IND_SIZE);
	}
	dir = random_direct();
	system_to_bin(&dir, DIR_SIZE);
	ft_memcpy(tmp_mem, &dir, DIR_SIZE);
	return (DIR_SIZE);
}

static void		set_name(char *buf, t_tst *p)
{
	ft_sprintf(buf, "%s, %s, %s, %s",
		g_names[p->a[0]],
		g_names[p->a[1]],
		g_names[p->a[2]],
		g_names[p->a[3]]);
}

void			gen_file(const char *dir, const t_op *op, int i, t_tst *p)
{
	int			j;
	int			a;
	int			fd;
	t_header	head;
	t_byte		tmp_mem[CHAMP_MAX_SIZE];

	ft_bzero(&head, sizeof(head));
	ft_bzero(tmp_mem, sizeof(tmp_mem));
	head.magic = COREWAR_EXEC_MAGIC;
	head.prog_size = CHAMP_MAX_SIZE;
	system_to_bin(&head.magic, sizeof(head.magic));
	system_to_bin(&head.prog_size, sizeof(head.prog_size));
	set_name(head.prog_name, p);
	ft_sprintf(head.comment, "%s/%u.cor", dir, i);
	if ((fd = open(head.comment, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
		exit(ft_print_error("%m\n"));
	j = 0 * write(fd, &head, sizeof(t_header));
	tmp_mem[j++] = op->id;
	if ((a = 0) || op->ocp)
		tmp_mem[j++] = gen_ocp(p);
	while (a < op->arg_cnt)
		j += gen_arg(&tmp_mem[j], op, p->a[a++]);
	while (j < CHAMP_MAX_SIZE)
		tmp_mem[j++] = random_byte();
	close(fd + (0 * write(fd, tmp_mem, CHAMP_MAX_SIZE)));
}
