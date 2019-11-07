/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/07 16:35:34 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "arena.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

char	op_fork(t_vm *vm, t_proc *proc)
{
	t_dir	val;
	t_ind	off;

	off = 1;
	get_dir2(proc, &off, &val);
	if (vm->verbosity & V_OPERATONS)
		ft_printf("P %4d | fork %d (%d)\n", proc->pid, val,
		proc->pc + (val % IDX_MOD));
	add_process(proc->pc + (val % IDX_MOD), proc);
	return (proc->carry);
}
