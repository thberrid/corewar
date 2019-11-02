/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:32:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/02 18:27:50 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_DISABLE_WARNINGS

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include "endianes.h"
#include "process.h"
#include "config.h"
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

static char	**parse_file(t_vm *vm, char **av)
{
	size_t		i;
	uint32_t	max;

	if (!*av)
		exit(ft_print_error("Missing player file after '-n %u'.\n",
			vm->players[vm->psize].pid));
	if (vm->psize >= MAX_PLAYERS)
		exit(ft_print_error("Can't add '%s': Too many players.\n", *av));
	if (!match(*av, "*.cor"))
		exit(ft_print_error("Invalid file: '%s'.\n", *av));
	vm->players[vm->psize].id = vm->psize;
	vm->players[vm->psize++].pc = (t_byte *)*av;
	if (vm->psize < MAX_PLAYERS)
	{
		i = 0;
		max = vm->players->pid;
		while (++i < vm->psize)
			if (max < vm->players[i].pid)
				max = vm->players[i].pid;
		vm->players[vm->psize].pid = max + 1;
	}
	return (av + 1);
}

static char	**parse_num(t_vm *vm, char **av)
{
	size_t		i;
	int64_t		v;
	uint32_t	r;

	i = 0;
	if (!*av)
		exit(ft_print_error("Missing value for %s.\n", av[-1]));
	if (!ft_isnumber(*av) || (v = atol(*av)) <= 0 || v > 0xffffffff)
		exit(ft_print_error("Invalid value for %s: '%s'", av[-1], *av));
	r = (uint32_t)v;
	while (i < vm->psize)
		if (vm->players[i++].pid == r)
			exit(ft_print_error("'%s %d' pid already taken.\n", av[-1], r));
	if (vm->psize < MAX_PLAYERS)
		vm->players[vm->psize].pid = r;
	return (parse_file(vm, av + 1));
}

static char	**parse_dump(t_vm *vm, char **av)
{
	int64_t	v;

	if (vm->dmp_bol)
		exit(ft_print_error("Doubled dump cycle.\n"));
	if (!*av)
		exit(ft_print_error("Missing value for %s.\n", av[-1]));
	if (!ft_isnumber(*av) || (v = atol(*av)) < 0 || v > 0xffffffff)
		exit(ft_print_error("Invalid value for %s: '%s'", av[-1], *av));
	vm->dmp_bol = 1 + (av[-1][1] == 'z');
	vm->dump = (uint32_t)v;
	return (av + 1);
}

static const t_dispatch	g_parser[] = {
	{"-zdump", parse_dump},
	{"-dump", parse_dump},
	{"-n", parse_num},
	{0, parse_file},
};

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

t_vm		parse_args(char **av)
{
	uint32_t	i;
	t_vm		vm;
	t_proc		*proc;

	ft_bzero(&vm, sizeof(vm));
	vm.players[0].pid = 1;
	vm.verbosity = VERBOSITY;
	while (av && *av)
	{
		i = 0;
		while (g_parser[i].opt && !ft_strequ(*av, g_parser[i].opt))
			++i;
		av = g_parser[i].callback(&vm, av + !!g_parser[i].opt);
	}
	if (!vm.psize)
		exit(ft_print_error("No player.\n"));
	i = 0;
	while (i < vm.psize)
	{
		load_file(&vm, vm.players + i, (char *)vm.players[i].pc);
		proc = add_process(vm.players[i].pc - g_map, NULL);
		proc->pid = vm.players[i].pid;
		proc->regs[0] = -vm.players[i++].pid;
	}
	return (vm);
}

/*
**	This is equivalent to invert the sign but slower.
**	Keeping it here in case the linux compiler doesn't like
**		to negate an unsigned value...
**
**	proc->regs[0] = 0xffffffffu - (vm.players[i++].pid - 1);
*/
