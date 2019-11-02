/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/02 18:39:01 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "arena.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

char	op_sub(t_vm *vm, t_proc *proc)
{
	t_byte	ocp;
	t_ind	off;
	t_byte	reg;
	t_reg	v1;
	t_reg	v2;

	ocp = g_map[proc->pc + 1 % MEM_SIZE];
	if ((off = check_ocp(ocp, OP_SUB)) && (proc->pc += off))
		return (proc->carry);
	off = 2;
	v1 = g_map[(proc->pc + off++) % MEM_SIZE];
	v2 = g_map[(proc->pc + off++) % MEM_SIZE];
	reg = g_map[(proc->pc + off++) % MEM_SIZE];
	if (vm->verbosity == V_OPERATONS)
		ft_printf("P %4d | sub r%d r%d r%d\n", proc->pid, v1, v2, reg);
	return (!(proc->regs[reg] = (v1 - v2)));
}
