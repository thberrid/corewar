/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/03 17:59:57 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "utils.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

char	op_xor(t_vm *vm, t_proc *proc)
{
	t_byte	ocp;
	t_ind	off;
	t_byte	reg;
	t_dir	v1;
	t_dir	v2;

	ocp = g_map[proc->pc + 1 % MEM_SIZE];
	if ((off = check_ocp(ocp, OP_XOR)) && (proc->pc += off))
		return (proc->carry);
	off = 2;
	v1 = (g_getter[((ocp >> 6) & 3)](proc, &off));
	v2 = (g_getter[((ocp >> 4) & 3)](proc, &off));
	reg = g_map[(proc->pc + off++) % MEM_SIZE];
	proc->pc += off;
	if (reg <= 0 || reg > REG_NUMBER)
		return (proc->carry);
	if (vm->verbosity & V_OPERATONS)
		ft_printf("P %4d | xor %d %d r%d\n", proc->pid, v1, v2, reg);
	return (!(proc->regs[reg - 1] = (v1 ^ v2)));
}
