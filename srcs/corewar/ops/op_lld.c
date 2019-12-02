/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/02 13:30:17 by abaurens         ###   ########.fr       */
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

static void	out(t_proc *proc, t_dir v1, t_dir v2)
{
	ft_putstr(proc->name);
	write(1, "lld ", 4);
	ft_putnbr(v1);
	write(1, " r", 2);
	ft_putnbr(v2);
	write(1, "\n", 1);
}

char		op_lld(t_vm *vm, t_proc *proc)
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
		out(proc, av.v1, av.v2);
	move_pc(vm, proc, off);
	return (!(proc->regs[av.v2 - 1] = av.v1));
}
