/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/01 21:56:54 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "config.h"
#include "arena.h"
#include "utils.h"
#include "vm.h"
#include "op.h"
#include "ftio.h"

char	op_or(t_vm *vm, t_proc *proc)
{
	t_byte	ocp;
	t_ind	off;
	t_byte	reg;
	t_dir	v1;
	t_dir	v2;

	ocp = g_map[proc->pc + 1 % MEM_SIZE];
	if ((off = check_ocp(ocp, OP_OR)) && (proc->pc += off))
		return (proc->carry);
	off = 2;
	v1 = (g_getter[((ocp >> 6) & 3)](proc, &off));
	v2 = (g_getter[((ocp >> 4) & 3)](proc, &off));
	reg = g_map[(proc->pc + off++) % MEM_SIZE];
	if (vm->verbosity == V_OPERATONS)
		ft_printf("P    1 | or %d %d r%d\n", v1, v2, reg);
	proc->regs[reg] = (v1 | v2);
	return (!v1);
}
