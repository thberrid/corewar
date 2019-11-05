/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/05 23:36:21 by abaurens         ###   ########.fr       */
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
	t_dir	val;

	ocp = g_map[proc->pc + 1 % MEM_SIZE];
	if ((off = check_ocp(ocp, OP_ST)) && (proc->pc += off))
		return (proc->carry);
	off = 2;
	reg = g_map[(proc->pc + off++) % MEM_SIZE];
/*	val = (g_getter[((ocp >> 4) & 3)](proc, &off));*/
	if ((mod = (((ocp >> 4) & 3) == REG_CODE)))
	{
		val = g_map[(proc->pc + off++) % MEM_SIZE];
	}
	else
	{
		;
	}
	if ((reg <= 0 || reg > REG_NUMBER) && (proc->pc += off))
		return (proc->carry);
	if (mod)
	{
		if ((val <= 0 || val > REG_NUMBER) && (proc->pc += off))
			return (proc->carry);
		ft_dprintf(2, "register : r%d\n", val);
	}
	else
	{

		ft_dprintf(2, "ind : %d\n", 0);
	}
	if (vm->verbosity & V_OPERATONS)
		ft_printf("P %4d | st r%d %d\n", proc->pid, reg, val);
	return (proc->carry);
}
