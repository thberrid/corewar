/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/05 16:22:02 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "arena.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

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
	v1 = (g_getter[((ocp >> 6) & 3)](proc, &off));
	v2 = (g_getter[((ocp >> 4) & 3)](proc, &off));
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
