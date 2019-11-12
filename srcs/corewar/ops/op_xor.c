/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/12 18:41:06 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftmath.h"
#include "ftlib.h"
#include "utils.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

static void	out(long int pid, t_dir v1, t_dir v2, t_dir v3)
{
	write(1, "P     ", ft_max(4 - ft_numlen(pid), 0) + 2);
	ft_putlnbr(pid);
	write(1, " | xor ", 7);
	ft_putnbr(v1);
	write(1, " ", 1);
	ft_putnbr(v2);
	write(1, " r", 2);
	ft_putnbr(v3);
	write(1, "\n", 1);
}

char		op_xor(t_vm *vm, t_proc *proc)
{
	t_args	av;
	t_ind	off;

	if (!(off = get_arguments(vm, proc, &av)))
		return (proc->carry);
	av.v1 = apply_type(proc, av.t1, 1, av.v1);
	av.v2 = apply_type(proc, av.t2, 1, av.v2);
	if (vm->verbosity & V_OPERATONS)
		out(proc->pid, av.v1, av.v2, av.v3);
	move_pc(vm, proc, off);
	return (!(proc->regs[av.v3 - 1] = (av.v1 ^ av.v2)));
}
