/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:20:59 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/03 20:49:35 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "process.h"
#include "arena.h"
#include "ftio.h"
#include "op.h"
#include "vm.h"

static void	vm_check(t_vm *vm)
{
	uint64_t	total_live;
	t_proc		*proc;

	total_live = 0;
	proc = g_procs.head;
	while (proc)
	{
		if (!proc->lives)
		{
			ft_printf("Process %d hasn't lived for %d cycles (CTD %lld)\n",
				proc->pid, vm->cycles - proc->last_live, vm->cycle_to_die);
			kill_process(proc);
		}
		total_live += proc->lives;
		proc->lives = 0;
		proc = proc->next;
	}
	if (total_live >= NBR_LIVE || ++vm->last_dec >= MAX_CHECKS)
	{
		vm->last_dec = 0;
		vm->cycle_to_die -= CYCLE_DELTA;
		ft_printf("Cycle to die is now %lld\n", vm->cycle_to_die);
	}
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
	uint32_t	last_check;

	last_check = 0;
	vm->cycles = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->verbosity = V_CYCLES | V_LIVES | V_OPERATONS;
	while (g_procs.size)
	{
		if (vm->dmp_bol && vm->cycles >= vm->dump)
			return ;
		++vm->cycles;
		if (vm->verbosity & V_CYCLES)
			ft_printf("It is now cycle %d\n", vm->cycles);
		proc = g_procs.head;
		while (proc)
		{
			vm_exec(vm, proc);
			proc = proc->next;
		}
		if ((vm->cycles - last_check) >= vm->cycle_to_die)
		{
			vm_check(vm);
			last_check = vm->cycles;
		}
	}
}
