/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/03 18:25:44 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "arena.h"
#include "utils.h"
#include "vm.h"
#include "op.h"

char	op_aff(t_vm *vm, t_proc *proc)
{
	t_byte	ocp;
	t_ind	off;
	t_byte	reg;

	ocp = g_map[proc->pc + 1 % MEM_SIZE];
	if ((off = check_ocp(ocp, OP_AFF)) && (proc->pc += off))
		return (proc->carry);
	off = 2;
	reg = g_map[(proc->pc + off++) % MEM_SIZE];
	proc->pc += off;
	if (reg <= 0 || reg > REG_NUMBER)
		return (proc->carry);
	if (vm->verbosity & V_AFF)
	{
		reg = proc->regs[reg - 1] % 256;
		write(1, "Aff: ", 5);
		write(1, &reg, 1);
		write(1, "\n", 1);
	}
	return (proc->carry);
}
