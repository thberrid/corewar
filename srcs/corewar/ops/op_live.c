/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/07 14:17:00 by abaurens         ###   ########.fr       */
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
	proc->last_live = vm->cycles;
	get_dir4(proc, &off, &val);
	if (vm->verbosity & V_OPERATONS)
		ft_printf("P %4d | live %d\n", proc->pid, val);
	proc->pc += off;
	if ((pl = get_player(vm, -val)) && (vm->verbosity & V_LIVES))
	{
		ft_printf("Player %d (%s) is said to be alive\n", pl->pid, pl->name);
		vm->winer = pl;
	}
	return (proc->carry);
}
