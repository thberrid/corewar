/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:11:35 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/08 22:45:33 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "arena.h"
#include "ftio.h"
#include "op.h"

t_dir	apply_type(t_proc *proc, t_byte type, t_byte mod, t_dir value)
{
	if (type == REG_CODE)
		return (proc->regs[value - 1]);
	if (type == IND_CODE)
	{
		if (mod)
			value %= IDX_MOD;
		map_to_var(&value, proc->pc + value, sizeof(value));
	}
	return (value);
}

t_byte	get_arguments(t_vm *vm, t_proc *proc, t_args *av)
{
	t_byte		er;
	t_byte		ocp;
	t_ind		of;
	const t_op	*op;

	er = 0;
	op = g_op_tab;
	while (op->name && op->id != g_map[proc->pc % MEM_SIZE])
		++op;
	ocp = g_map[(proc->pc + 1) % MEM_SIZE];
	if ((check_ocp(ocp, op->id, &of)) && move_pc(vm, proc, 2 + of))
		return (0);
	of = 2;
	if (op->arg_cnt > 0 && (av->t1 = ((ocp >> 6) & 3)))
		er |= g_arg[av->t1](proc, &of, &(av->v1));
	if (op->arg_cnt > 1 && (av->t2 = ((ocp >> 4) & 3)))
		er |= g_arg[av->t2](proc, &of, &(av->v2));
	if (op->arg_cnt > 2 && (av->t3 = ((ocp >> 2) & 3)))
		er |= g_arg[av->t3](proc, &of, &(av->v3));
	if (op->arg_cnt > 3 && (av->t4 = (ocp & 3)))
		er |= g_arg[av->t4](proc, &of, &(av->v4));
	if (er)
		move_pc(vm, proc, of);
	return ((!er) * of);
}
