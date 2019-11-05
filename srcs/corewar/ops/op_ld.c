/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/05 12:43:38 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_DISABLE_WARNINGS

#include "utils.h"
#include "arena.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

char	op_ld(t_vm *vm, t_proc *proc)
{
	t_byte	reg;
	t_byte	ocp;
	t_dir	val;
	t_ind	off;

	ocp = g_map[proc->pc + 1 % MEM_SIZE];
	if ((off = check_ocp(ocp, OP_LD)) && (proc->pc += off))
		return (proc->carry);
	off = 2;
	val = (g_getter[((ocp >> 6) & 3)](proc, &off));
	reg = g_map[(proc->pc + off++) % MEM_SIZE];
	if ((reg <= 0 || reg > REG_NUMBER) && (proc->pc += off))
		return (proc->carry);
	if (vm->verbosity & V_OPERATONS)
		ft_printf("P %4d | ld %d r%d\n", proc->pid, val, reg);
	return (!(proc->regs[reg - 1] = val));
}
