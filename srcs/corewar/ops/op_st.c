/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/07 15:40:49 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "utils.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

char			op_st(t_vm *vm, t_proc *proc)
{
	t_args	av;
	t_ind	off;

	if (!(off = get_arguments(vm, proc, &av)))
		return (proc->carry);
	if (vm->verbosity & V_OPERATONS)
		ft_printf("P %4d | st r%d %d\n", proc->pid, av.v1, av.v2);
	av.v1 = apply_type(proc, av.t1, 1, av.v1);
	if (av.t2 == REG_CODE)
		proc->regs[av.v2 - 1] = av.v1;
	else
		dir_to_map(proc, av.v2 % IDX_MOD, av.v1);
	move_pc(vm, proc, off);
	return (proc->carry);
}
