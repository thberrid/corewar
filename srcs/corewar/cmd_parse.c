/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:32:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/05 16:38:02 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_DISABLE_WARNINGS

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "endianes.h"
#include "process.h"
#include "parser.h"
#include "arena.h"
#include "ftlib.h"
#include "ftio.h"
#include "vm.h"

/*
**	./corewar [-dump nb_cycles] [[-n num] champ1.cor] ...
**	-dump suivi d'un nombre, n'importe ou dans la commande excepte
**	entre un -n et son num ou entre un -n et son champion.
**	-n suivi d'un nombre puis d'un champion, partout excepte entre -dump et
**	son nombre
**
**	les nombres sont des unsigned int de 32 bit de long (uint32_t)
*/

static void	load_file(t_vm *vm, t_champ *chmp, const char *path)
{
	int			fd;
	ssize_t		rd;
	t_header	head;

	chmp->pc = g_map + (MEM_SIZE / vm->psize * chmp->id);
	if ((fd = open(path, O_RDONLY)) < 0)
		exit(ft_print_error("Can't open '%s': %m.\n", path));
	if ((rd = read(fd, &head, sizeof(head))) < 0 && (close(fd) | 1))
		exit(ft_print_error("can't read '%s': %m.\n", path));
	if ((size_t)rd < sizeof(head) && (close(fd) | 1))
		exit(ft_print_error("'%s': Invalid or corrupted file.\n", path));
	bin_to_system(&head.magic, sizeof(head.magic));
	bin_to_system(&head.prog_size, sizeof(head.prog_size));
	if (head.magic != COREWAR_EXEC_MAGIC && (close(fd) | 1))
		exit(ft_print_error("'%s': Invalid or corrupted file.\n", path));
	if ((chmp->size = head.prog_size) > CHAMP_MAX_SIZE && (close(fd) | 1))
		exit(ft_print_error("'%s': File too big.\n", path));
	if ((rd = read(fd, chmp->pc, head.prog_size)) < 0)
		exit(ft_print_error("can't read '%s': %m.\n", path));
	if (close(fd) < 0)
		exit(ft_print_error("can't close fd '%d': %m.\n", fd));
	if (rd < head.prog_size)
		exit(ft_print_error("'%s': Invalid or corrupted file.\n", path));
	ft_strcpy(chmp->comm, head.comment);
	ft_strcpy(chmp->name, head.prog_name);
}

void		parse_args(t_vm *vm, char **av)
{
	uint32_t	i;
	t_proc		*proc;

	ft_bzero(vm, sizeof(t_vm));
	vm->players[0].pid = 1;
	while (av && *av)
	{
		i = 0;
		while (g_parser[i].opt && !ft_strequ(*av, g_parser[i].opt))
			++i;
		av = g_parser[i].callback(vm, av + !!g_parser[i].opt);
	}
	if (!vm->psize)
		exit(ft_print_error("No player.\n"));
	i = 0;
	while (i < vm->psize)
	{
		load_file(vm, vm->players + i, (char *)vm->players[i].pc);
		proc = add_process(vm->players[i].pc - g_map, NULL);
		if (!vm->winer || vm->winer->pid < vm->players[i].pid)
			vm->winer = vm->players + i;
		proc->pid = vm->players[i].pid;
		proc->regs[0] = -vm->players[i++].pid;
	}
}

/*
**	This is equivalent to invert the sign but slower.
**	Keeping it here in case the linux compiler doesn't like
**		to negate an unsigned value...
**
**	proc->regs[0] = 0xffffffffu - (vm->players[i++].pid - 1);
*/
