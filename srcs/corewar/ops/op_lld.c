/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/07 12:54:21 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "arena.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

static t_dir	lld_get_ind(t_proc *proc, t_ind *off)
{
	t_ind	addr;

	addr = (g_map[(proc->pc + *off) % MEM_SIZE] << 8)
		| g_map[(proc->pc + *off + 1) % MEM_SIZE];
	(*off) += 2;
	map_to_var(&addr, proc->pc + addr, sizeof(addr));
	return (addr);
}

char			op_lld(t_vm *vm, t_proc *proc)
{
	t_byte	reg;
	t_byte	ocp;
	t_dir	val;
	t_ind	off;

	ocp = g_map[proc->pc + 1 % MEM_SIZE];
	if ((off = check_ocp(ocp, OP_LLD)) && (proc->pc += off))
		return (proc->carry);
	off = 2;
	if (((ocp >> 6) & 3) == IND_CODE)
		val = lld_get_ind(proc, &off);
	else
		g_getter[((ocp >> 6) & 3)](proc, &off, &val);
	reg = g_map[(proc->pc + off++) % MEM_SIZE];
	if ((reg <= 0 || reg > REG_NUMBER) && (proc->pc += off))
		return (proc->carry);
	if (vm->verbosity & V_OPERATONS)
		ft_printf("P %4d | lld %d r%d\n", proc->pid, val, reg);
	proc->pc += off;
	return (!(proc->regs[reg - 1] = val));
}
