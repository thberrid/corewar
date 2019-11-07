/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/07 15:33:01 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

char	op_zjmp(t_vm *vm, t_proc *proc)
{
	t_ind	off;
	t_dir	val;

	off = 1;
	get_dir4(proc, &off, &val);
	move_pc(vm, proc, off);
	if (proc->carry)
		off = val;
	if (vm->verbosity & V_OPERATONS)
		ft_printf("P %4d | zjmp %d %s\n", proc->pid, val,
			proc->carry ? "OK" : "FAILED");
	return (proc->carry);
}
