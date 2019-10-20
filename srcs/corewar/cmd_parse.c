/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:32:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/17 20:40:32 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
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
		exit(ft_print_error("Can't add '%s': Too much players.\n", *av));
	if (!match(*av, "*.cor"))
		exit(ft_print_error("Invalid file: '%s'", *av));
	if ((vm->players[vm->psize++].fd = open(*av, O_RDONLY)) < 0)
		exit(ft_print_error("Can't open '%s': %m.\n", *av));
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
	vm->dmp_bol = 1;
	vm->dump = (uint32_t)v;
	return (av + 1);
}

static const t_dispatch	g_parser[] = {
	{"-dump", parse_dump},
	{"-n", parse_num},
	{0, parse_file},
};

t_vm		parse_args(char **av)
{
	int		i;
	t_vm	vm;

	i = 0;
	ft_bzero(&vm, sizeof(vm));
	vm.players[0].pid = 1;
	while (av && *av)
	{
		while (g_parser[i].opt && !ft_strequ(*av, g_parser[i].opt))
			++i;
		av = g_parser[i].callback(&vm, av + !!g_parser[i].opt);
	}
	if (!vm.psize)
		exit(ft_print_error("No player.\n"));
	return (vm);
}
