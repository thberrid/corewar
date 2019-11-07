/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/07 21:05:38 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "arena.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

char			op_lld(t_vm *vm, t_proc *proc)
{
	t_args	av;
	t_ind	tmp;
	t_ind	off;

	if (!(off = get_arguments(vm, proc, &av)))
		return (proc->carry);
	if (av.t1 == IND_CODE)
	{
		map_to_var(&tmp, proc->pc + av.v1, sizeof(tmp));
		av.v1 = tmp;
	}
	else
		av.v1 = apply_type(proc, av.t1, 0, av.v1);
	if (vm->verbosity & V_OPERATONS)
		ft_printf("P %4d | lld %d r%d\n", proc->pid, av.v1, av.v2);
	move_pc(vm, proc, off);
	return (!(proc->regs[av.v2 - 1] = av.v1));
}
