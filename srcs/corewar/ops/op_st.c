/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/07 11:26:22 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "utils.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

static t_byte	st_indirect(t_proc *proc, t_byte reg, t_ind *val)
{
	if ((reg <= 0 || reg > REG_NUMBER) && (proc->pc += 5))
		return (1);
	map_to_var(val, proc->pc + 3, sizeof(*val));
	dir_to_map(proc, *val % IDX_MOD, proc->regs[reg - 1]);
	proc->pc += 5;
	return (0);
}

static t_byte	st_register(t_proc *proc, t_byte reg, t_ind *val)
{
	*val = g_map[(proc->pc + 3) % MEM_SIZE];
	proc->pc += 4;
	if ((reg <= 0 || reg > REG_NUMBER) || (*val <= 0 || *val > REG_NUMBER))
		return (1);
	proc->regs[*val - 1] = proc->regs[reg - 1];
	return (0);
}

char			op_st(t_vm *vm, t_proc *proc)
{
	t_byte	ocp;
	t_byte	reg;
	t_ind	off;
	t_ind	val;

	ocp = g_map[proc->pc + 1 % MEM_SIZE];
	if ((off = check_ocp(ocp, OP_ST)) && (proc->pc += off))
		return (proc->carry);
	reg = g_map[(proc->pc + 2) % MEM_SIZE];
	ocp = ((ocp >> 4) & 3);
	if (ocp == IND_CODE && st_indirect(proc, reg, &val))
		return (proc->carry);
	else if (ocp == REG_CODE && st_register(proc, reg, &val))
		return (proc->carry);
	if (vm->verbosity & V_OPERATONS)
		ft_printf("P %4d | st r%d %d\n", proc->pid, reg, val);
	return (proc->carry);
}
