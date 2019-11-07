/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 07:24:26 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/07 16:50:07 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_DISABLE_WARNINGS

#include <unistd.h>
#include <stdlib.h>
#include "process.h"
#include "arena.h"
#include "ftlib.h"
#include "ftio.h"
#include "vm.h"

#define REG_COLUMNS	8

t_byte	g_map[MEM_SIZE];
t_lst	g_procs;

static void	print_process(void)
{
	size_t		v;
	size_t		l;
	size_t		i;
	size_t		r;
	t_proc		*cur;

	i = 0;
	cur = g_procs.head;
	while (cur)
	{
		ft_printf("\33[35m[process %zu]\33[0m\n", ++i);
		ft_printf(" \33[31mpc:     %hu\33[0m\n", cur->pc);
		ft_printf(" \33[33mcarry:  %d\33[0m\n", cur->carry);
		l = 0;
		while (l < REG_NUMBER / REG_COLUMNS)
		{
			r = 0;
			while ((v = r++ * (REG_NUMBER / REG_COLUMNS) + l) < REG_NUMBER)
				ft_printf("  [\33[3%dmr%zu:%s % d\33[0m]",
					7 + ((r % 2 == l % 2)), v, v < 10 ? " " : "", cur->regs[v]);
			ft_printf("\n");
			++l;
		}
		cur = cur->next;
	}
}

static void	print_vm_state(t_vm *vm)
{
	size_t	i;

	i = 0;
	ft_printf("dump:   %u\n", vm->dump);
	ft_printf("players: %zu\n", vm->psize);
	while (i < MAX_PLAYERS)
	{
		ft_printf("champ[%zu]:\n", i);
		ft_printf("  id:   %u\n", vm->players[i].id);
		ft_printf("  pid:  %08x (%u)\n", vm->players[i].pid,
											vm->players[i].pid);
		ft_printf("  name: \"%s\"\n", vm->players[i].name);
		++i;
	}
	ft_printf("\n");
	print_process();
}

t_champ		*get_player(t_vm *vm, uint32_t pid)
{
	uint32_t	i;
	t_champ		*p;

	i = 0;
	p = vm->players;
	while (i++ < vm->psize)
	{
		if (p->pid == pid)
			return (p);
		p++;
	}
	return (NULL);
}

void		destruct(void)
{
	clear_procs();
}

int			main(int ac __attribute__((unused)), char **av)
{
	size_t	i;
	t_vm	vm;

	i = 0;
	ft_bzero(&g_procs, sizeof(t_lst));
	parse_args(&vm, av + 1);
	ft_putstr("Introducing contestants...\n");
	while (i < vm.psize)
	{
		ft_printf("* Player %lu, weighing %zu bytes, \"%s\" (\"%s\") !\n",
				vm.players[i].pid, vm.players[i].size,
				vm.players[i].name, vm.players[i].comm);
		++i;
	}
	if (0)
		print_vm_state(&vm);
	vm_loop(&vm);
	if (vm.dmp_bol)
		vm_dump(DUMP_LEN * vm.dmp_bol);
	else
		ft_printf("Contestant %d, \"%s\", has won !\n",
			vm.winer->pid, vm.winer->name);
	return (0);
}
