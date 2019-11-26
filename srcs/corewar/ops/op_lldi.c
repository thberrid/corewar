/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/14 00:08:43 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftmath.h"
#include "ftlib.h"
#include "utils.h"
#include "arena.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

static void	out(t_proc *proc, t_dir v1, t_dir v2, t_dir v3)
{
	write(1, "P     ", ft_max(4.0 - ft_numlen(proc->pid), 0) + 2);
	ft_putlnbr(proc->pid);
	write(1, " | lldi ", 8);
	ft_putnbr(v1);
	write(1, " ", 1);
	ft_putnbr(v2);
	write(1, " r", 2);
	ft_putnbr(v3);
	write(1, "\n", 1);
	write(1, "       | -> load from ", 22);
	ft_putnbr(v1);
	write(1, " + ", 3);
	ft_putnbr(v2);
	write(1, " = ", 3);
	ft_putnbr(v1 + v2);
	write(1, " (with pc ", 10);
	ft_putnbr(proc->pc + v1 + v2);
	write(1, ")\n", 2);
}

char		op_lldi(t_vm *vm, t_proc *proc)
{
	t_args	av;
	t_dir	val;
	t_ind	off;

	if (!(off = get_arguments(vm, proc, &av)))
		return (proc->carry);
	av.v1 = apply_type(proc, av.t1, 1, av.v1);
	av.v2 = apply_type(proc, av.t2, 1, av.v2);
	if (vm->verbosity & V_OPERATONS)
		out(proc, av.v1, av.v2, av.v3);
	map_to_var(&val, proc->pc + av.v1 + av.v2, sizeof(val));
	move_pc(vm, proc, off);
	return (!(proc->regs[av.v3 - 1] = val));
}
