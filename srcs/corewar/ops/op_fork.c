/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/03 02:25:31 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftmath.h"
#include "output.h"
#include "ftlib.h"
#include "utils.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

static void	out(t_proc *proc, t_dir v1, t_dir v2)
{
	corewar_putstr(1, proc->name);
	corewar_write(1, "fork ", 5);
	corewar_putnbr(1, v1);
	corewar_write(1, " (", 2);
	corewar_putnbr(1, v2);
	corewar_write(1, ")\n", 2);
}

char		op_fork(t_vm *vm, t_proc *proc)
{
	t_dir	val;
	t_ind	off;

	off = 1;
	get_dir2(proc, &off, &val);
	if (vm->verbosity & V_OPERATONS)
		out(proc, val, proc->pc + (val % IDX_MOD));
	add_process(proc->pc + (val % IDX_MOD), proc);
	move_pc(vm, proc, 3);
	return (proc->carry);
}
