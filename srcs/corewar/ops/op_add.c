/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:04:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/03 17:59:36 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "arena.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

char	op_add(t_vm *vm, t_proc *proc)
{
	t_byte	ocp;
	t_ind	off;
	t_byte	reg;
	t_reg	v1;
	t_reg	v2;

	ocp = g_map[proc->pc + 1 % MEM_SIZE];
	if ((off = check_ocp(ocp, OP_ADD)) && (proc->pc += off))
		return (proc->carry);
	off = 2;
	v1 = g_map[(proc->pc + off++) % MEM_SIZE];
	v2 = g_map[(proc->pc + off++) % MEM_SIZE];
	reg = g_map[(proc->pc + off++) % MEM_SIZE];
	proc->pc += off;
	if (reg <= 0 || reg > REG_NUMBER)
		return (proc->carry);
	if (vm->verbosity & V_OPERATONS)
		ft_printf("P %4d | add r%d r%d r%d\n", proc->pid, v1, v2, reg);
	return (!(proc->regs[reg - 1] = (v1 + v2)));
}
