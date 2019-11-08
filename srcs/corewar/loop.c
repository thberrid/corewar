/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:20:59 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/08 18:24:52 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "process.h"
#include "arena.h"
#include "ftio.h"
#include "op.h"
#include "vm.h"

static t_proc	*vm_kill(t_vm *vm, t_proc *proc)
{
	if (vm->verbosity & V_DEATHS)
		ft_printf("Process %d hasn't lived for %d cycles (CTD %ld)\n",
			proc->pid, vm->cycles - proc->last_live, vm->cycle_to_die);
	return (kill_process(proc));
}

/*
**	zaz:
**	3278	It is now cycle 3072
**	3279	Process 13 hasn't lived for 1866 cycles (CTD 1536)
**	3280	Process 11 hasn't lived for 1611 cycles (CTD 1536)
**	3281	Process 7 hasn't lived for 1866 cycles (CTD 1536)
**
**	3559	P   12 | live 367872286
**	3594	P   12 | live -1570065708
**	3640	P   12 | live 1974229750
*/

/*
**	my:
**	3278	It is now cycle 3072
**	3279	Process 13 hasn't lived for 1866 cycles (CTD 1536)
**	3280	Process 12 hasn't lived for 3072 cycles (CTD 1536)
**	3281	Process 11 hasn't lived for 1611 cycles (CTD 1536)
**	3282	Process 7 hasn't lived for 1866 cycles (CTD 1536)
*/

static void		vm_check(t_vm *vm)
{
	t_proc		*proc;

	proc = g_procs.head;
	while (proc)
	{
		if (!proc->lives)
		{
			proc = vm_kill(vm, proc);
			continue ;
		}
		proc->lives = 0;
		proc = proc->next;
	}
	vm->last_dec++;
	if (vm->total_live >= NBR_LIVE || vm->last_dec >= MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		if (vm->verbosity & V_CYCLES)
		{
			ft_printf("Cycle to die is now %ld\n", vm->cycle_to_die);
		}
		vm->last_dec = 0;
	}
	vm->total_live = 0;
}

static void		vm_exec(t_vm *vm, t_proc *proc)
{
	t_byte				cur;
	register const t_op	*op;

	op = g_op_tab;
	cur = g_map[proc->pc % MEM_SIZE];
	while (op->name && cur != op->id)
		op++;
	if (++proc->time_to_wait >= op->cost)
	{
		proc->time_to_wait = 0;
		if (op->fnc)
			proc->carry = op->fnc(vm, proc);
		else
			proc->pc++;
		proc->pc %= MEM_SIZE;
	}
}

void			vm_loop(t_vm *vm)
{
	t_proc		*proc;
	uint32_t	last_check;

	last_check = 0;
	vm->cycles = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
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
