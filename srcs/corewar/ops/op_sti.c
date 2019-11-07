/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/07 13:15:59 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "utils.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

char	op_sti(t_vm *vm, t_proc *proc)
{
	t_args	av;
	t_ind	off;

	if (!(off = get_arguments(proc, &av)))
		return (proc->carry);
	if (av.t2 == REG_CODE)
		av.v2 = proc->regs[av.v2 - 1];
	if (av.t3 == REG_CODE)
		av.v3 = proc->regs[av.v3 - 1];
	if (vm->verbosity & V_OPERATONS)
	{
		ft_printf("P %4d | sti r%d %d %d\n", proc->pid, av.v1, av.v2, av.v3);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
			av.v2, av.v3, (av.v2 + av.v3),
			(proc->pc + ((av.v2 + av.v3) % IDX_MOD)) % MEM_SIZE);
	}
	dir_to_map(proc, (av.v2 + av.v3) % IDX_MOD, proc->regs[av.v1 - 1]);
	proc->pc += off;
	return (proc->carry);
}

/*
char	op_sti(t_vm *vm, t_proc *proc)
{
	t_byte	ocp;
	t_byte	reg;
	t_ind	off;
	t_dir	v2;
	t_dir	v1;

	ocp = g_map[proc->pc + 1 % MEM_SIZE];
	if ((off = check_ocp(ocp, OP_STI)) && (proc->pc += off))
		return (proc->carry);
	off = 2;
	reg = g_map[(proc->pc + off++) % MEM_SIZE];
	v1 = (g_getter[((ocp >> 4) & 3)](proc, &off));
	v2 = (g_getter[((ocp >> 2) & 3)](proc, &off));
	if ((reg <= 0 || reg > REG_NUMBER) && (proc->pc += off))
		return (proc->carry);
	if (vm->verbosity & V_OPERATONS)
	{
		ft_printf("P %4d | sti r%d %d %d\n", proc->pid, reg, v1, v2);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
			v1, v2, (v1 + v2), (proc->pc + ((v1 + v2) % IDX_MOD)) % MEM_SIZE);
	}
	dir_to_map(proc, (v1 + v2) % IDX_MOD, proc->regs[reg - 1]);
	proc->pc += off;
	return (proc->carry);
}*/
