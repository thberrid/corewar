/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/12 22:09:41 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "arena.h"
#include "utils.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

static void	out_aff(const char c)
{
	write(1, "Aff: ", 5);
	write(1, &c, 1);
	write(1, "\n", 1);
}

char		op_aff(t_vm *vm, t_proc *proc)
{
	t_args	av;
	t_ind	off;

	if (!(off = get_arguments(vm, proc, &av)))
		return (proc->carry);
	av.v1 = apply_type(proc, av.t1, 1, av.v1);
	if (vm->verbosity & V_AFF)
		out_aff(av.v1 % 256);
	move_pc(vm, proc, off);
	return (proc->carry);
}
