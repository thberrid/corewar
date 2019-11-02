/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:20:59 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/01 19:14:06 by abaurens         ###   ########.fr       */
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
	t_byte				cur;
	register const t_op	*op;

	op = g_op_tab;
	cur = g_map[proc->pc % MEM_SIZE];
	while (op->name && cur != op->id)
		op++;
	if (op->fnc)
	{
		if (++proc->time_to_wait >= op->cost)
		{
			proc->time_to_wait = 0;
			proc->carry = op->fnc(vm, proc);
		}
	}
	else
		++proc->pc;
}

void		vm_loop(t_vm *vm)
{
	t_proc		*proc;
	uint32_t	cycles;
	uint32_t	cycle_to_die;

	cycles = 0;
	(void)(cycle_to_die);
	cycle_to_die = CYCLE_TO_DIE;
	while (g_procs.size)
	{
		if (vm->dmp_bol && cycles >= vm->dump)
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
