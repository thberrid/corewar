/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/23 09:08:57 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "arena.h"
#include "vm.h"
#include "op.h"

char	op_sti(t_vm *vm, t_proc *proc)
{
	t_byte	ocp;
	t_ind	off;
	t_dir	val;
	t_ind	v;

	(void)vm;
	ocp = g_map[proc->pc + 1 % MEM_SIZE];
	if ((off = check_ocp(ocp, OP_STI)) && (proc->pc += off))
		return (proc->carry);
	off = 2;
	val = get_reg(proc, &off);
	v = (g_getter[((ocp >> 4) & 3)](proc, &off) & 0xffff);
	v += (g_getter[((ocp >> 2) & 3)](proc, &off) & 0xffff);
	v = (int16_t)(v % MEM_SIZE) % IDX_MOD;
	dir_to_map(proc, v, val);
	proc->pc += off;
	return (proc->carry);
}
