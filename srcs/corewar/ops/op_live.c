/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/08 23:27:03 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

char	op_live(t_vm *vm, t_proc *proc)
{
	t_ind	off;
	t_dir	val;
	t_champ	*pl;

	off = 1;
	proc->lives++;
	vm->total_live++;
	proc->last_live = vm->cycles;
	get_dir4(proc, &off, &val);
	if (vm->verbosity & V_OPERATONS)
		ft_printf("P %4d | live %d\n", proc->pid, val);
	if ((pl = get_player(vm, -val)) && (vm->verbosity & V_LIVES))
	{
		ft_printf(LIVMSG, pl->pid, pl->name);
		vm->winer = pl;
	}
	move_pc(vm, proc, off);
	return (proc->carry);
}
