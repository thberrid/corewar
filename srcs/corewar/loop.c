/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:20:59 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/22 15:55:40 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "process.h"
#include "arena.h"
#include "ftio.h"
#include "op.h"
#include "vm.h"

static void	vm_check(void)
{
	ft_printf("check\n");
	exit(0);
}

static void	vm_exec(t_vm *vm, t_proc *proc)
{
	(void)vm;
	if (g_map[proc->pc % MEM_SIZE] < sizeof(g_op_tab) / sizeof(t_op))
		proc->carry = g_op_tab[g_map[proc->pc % MEM_SIZE]].fnc(vm, proc);
	else
		++proc->pc;
}

void		vm_loop(t_vm *vm)
{
	t_proc		*proc;
	uint32_t	cycles;
	uint32_t	cycle_to_die;

	cycles = 0;
	cycle_to_die = CYCLE_TO_DIE;
	while (g_procs.size)
	{
		if (vm->dmp_bol && cycles > vm->dump)
			return ;
		if (++cycles >= CYCLE_TO_DIE)
		{
			vm_check();
			vm->dump -= (vm->dmp_bol * cycles);
			cycles = 0;
		}
		proc = g_procs.head;
		while (proc)
		{
			vm_exec(vm, proc);
			proc = proc->next;
		}
	}
}
