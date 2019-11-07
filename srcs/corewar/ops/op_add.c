/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:04:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/07 15:31:30 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "utils.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

char	op_add(t_vm *vm, t_proc *proc)
{
	t_args	av;
	t_ind	off;

	if (!(off = get_arguments(vm, proc, &av)))
		return (proc->carry);
	if (vm->verbosity & V_OPERATONS)
		ft_printf("P %4d | add r%d r%d r%d\n", proc->pid, av.v1, av.v2, av.v3);
	av.v1 = proc->regs[av.v1 - 1];
	av.v2 = proc->regs[av.v2 - 1];
	move_pc(vm, proc, off);
	return (!(proc->regs[av.v3 - 1] = (av.v1 + av.v2)));
}
