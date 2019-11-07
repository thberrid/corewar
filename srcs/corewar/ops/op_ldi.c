/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/07 13:52:39 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "arena.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

char	op_ldi(t_vm *vm, t_proc *proc)
{
	t_args	av;
	t_dir	val;
	t_ind	off;

	if (!(off = get_arguments(proc, &av)))
		return (proc->carry);
	if (av.t1 == REG_CODE)
		av.v1 = proc->regs[av.v1 - 1];
	if (av.t2 == REG_CODE)
		av.v2 = proc->regs[av.v2 - 1];
	if (vm->verbosity & V_OPERATONS)
	{
		ft_printf("P %4d | ldi %d %d r%d\n", proc->pid, av.v1, av.v2, av.v3);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
			av.v1, av.v2, (av.v1 + av.v2),
			(proc->pc + ((av.v1 + av.v2) % IDX_MOD)) % MEM_SIZE);
	}
	map_to_var(&val, proc->pc + ((av.v1 + av.v2) % IDX_MOD), sizeof(val));
	proc->regs[av.v3 - 1] = val;
	proc->pc += off;
	return (proc->carry);
}

/*
char	op_ldi(t_vm *vm, t_proc *proc)
{
	t_byte	reg;
	t_byte	ocp;
	t_ind	off;
	t_dir	v1;
	t_dir	v2;

	ocp = g_map[proc->pc + 1 % MEM_SIZE];
	if ((off = check_ocp(ocp, OP_LDI)) && (proc->pc += off))
		return (proc->carry);
	off = 2;
	g_getter[((ocp >> 6) & 3)](proc, &off, &v1);
	g_getter[((ocp >> 4) & 3)](proc, &off, &v2);
	reg = g_map[(proc->pc + off++) % MEM_SIZE];
	if ((reg <= 0 || reg > REG_NUMBER) && (proc->pc += off))
		return (proc->carry);
	if (vm->verbosity & V_OPERATONS)
	{
		ft_printf("P %4d | ldi %d %d r%d\n", proc->pid, v1, v2, reg);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
			v1, v2, (v1 + v2), (proc->pc + ((v1 + v2) % IDX_MOD)) % MEM_SIZE);
	}
	map_to_var(&v1, proc->pc + ((v1 + v2) % IDX_MOD), sizeof(v1));
	proc->regs[reg - 1] = v1;
	proc->pc += off;
	return (proc->carry);
}
*/
