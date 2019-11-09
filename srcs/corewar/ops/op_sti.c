/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/09 04:45:27 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "arena.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

char	op_sti(t_vm *vm, t_proc *proc)
{
	t_args	av;
	t_ind	off;

	if (!(off = get_arguments(vm, proc, &av)))
		return (proc->carry);
	av.v2 = apply_type(proc, av.t2, 1, av.v2);
	av.v3 = apply_type(proc, av.t3, 1, av.v3);
	if (vm->verbosity & V_OPERATONS)
	{
		ft_printf("P %4d | sti r%d %d %d\n", proc->pid, av.v1, av.v2, av.v3);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
			av.v2, av.v3, (av.v2 + av.v3),
			(proc->pc + ((av.v2 + av.v3) % IDX_MOD)) % MEM_SIZE);
	}
	dir_to_map(proc, (av.v2 + av.v3) % IDX_MOD, proc->regs[av.v1 - 1]);
	move_pc(vm, proc, off);
	return (proc->carry);
}
