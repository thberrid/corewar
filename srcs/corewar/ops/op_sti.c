/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/02 18:38:51 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "utils.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

char	op_sti(t_vm *vm, t_proc *proc)
{
	t_byte	ocp;
	t_ind	off;
	t_dir	val;
	t_dir	v2;
	t_dir	v1;

	ocp = g_map[proc->pc + 1 % MEM_SIZE];
	if ((off = check_ocp(ocp, OP_STI)) && (proc->pc += off))
		return (proc->carry);
	off = 2;
	val = get_reg(proc, &off);
	v1 = (g_getter[((ocp >> 4) & 3)](proc, &off));
	v2 = (g_getter[((ocp >> 2) & 3)](proc, &off));
	if (vm->verbosity == V_OPERATONS)
	{
		ft_printf("P %4d | sti r%d %d %d\n", proc->pid,
			g_map[(proc->pc + 2) % MEM_SIZE], v1, v2);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
			v1, v2, (v1 + v2), ((proc->pc + v1 + v2) % MEM_SIZE) % IDX_MOD);
	}
	dir_to_map(proc, ((v1 + v2) % MEM_SIZE) % IDX_MOD, val);
	proc->pc += off;
	return (proc->carry);
}
