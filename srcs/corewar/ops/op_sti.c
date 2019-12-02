/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/02 13:29:55 by abaurens         ###   ########.fr       */
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
	ft_putstr(proc->name);
	write(1, "sti r", 5);
	ft_putnbr(v1);
	write(1, " ", 1);
	ft_putnbr(v2);
	write(1, " ", 1);
	ft_putnbr(v3);
	write(1, "\n", 1);
	write(1, "       | -> store to ", 21);
	ft_putnbr(v2);
	write(1, " + ", 3);
	ft_putnbr(v3);
	write(1, " = ", 3);
	ft_putnbr(v2 + v3);
	write(1, " (with pc and mod ", 18);
	ft_putnbr((proc->pc + ((v2 + v3) % IDX_MOD)) % MEM_SIZE);
	write(1, ")\n", 2);
}

char		op_sti(t_vm *vm, t_proc *proc)
{
	t_args	av;
	t_ind	off;

	if (!(off = get_arguments(vm, proc, &av)))
		return (proc->carry);
	av.v2 = apply_type(proc, av.t2, 1, av.v2);
	av.v3 = apply_type(proc, av.t3, 1, av.v3);
	if (vm->verbosity & V_OPERATONS)
		out(proc, av.v1, av.v2, av.v3);
	dir_to_map(proc, (av.v2 + av.v3) % IDX_MOD, proc->regs[av.v1 - 1]);
	move_pc(vm, proc, off);
	return (proc->carry);
}
