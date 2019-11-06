/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/06 20:02:52 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "utils.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

char	op_st(t_vm *vm, t_proc *proc)
{
	t_byte	ocp;
	t_byte	reg;
	t_byte	mod;
	t_ind	off;
	t_ind	val;

	ocp = g_map[proc->pc + 1 % MEM_SIZE];
	if ((off = check_ocp(ocp, OP_ST)) && (proc->pc += off))
		return (proc->carry);
	off = 2;
	reg = g_map[(proc->pc + off++) % MEM_SIZE];
	if ((mod = (((ocp >> 4) & 3) == REG_CODE)))
		val = g_map[(proc->pc + off++) % MEM_SIZE];
	else
	{
		map_to_var(&val, proc->pc + off, sizeof(val));
		off += 2;
	}
	if ((reg <= 0 || reg > REG_NUMBER) && (proc->pc += off))
		return (proc->carry);
	if (mod)
	{
		if ((val <= 0 || val > REG_NUMBER) && (proc->pc += off))
			return (proc->carry);
		proc->regs[val - 1] = proc->regs[reg - 1];
	}
	else
		dir_to_map(proc, val % IDX_MOD, proc->regs[reg - 1]);
	if (vm->verbosity & V_OPERATONS)
		ft_printf("P %4d | st r%d %d\n", proc->pid, reg, val);
	proc->pc += off;
	return (proc->carry);
}
