/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/03 02:38:32 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ftmath.h"
#include "output.h"
#include "ftlib.h"
#include "utils.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

static void	out(t_proc *proc, t_dir v1)
{
	corewar_putstr(1, proc->name);
	corewar_write(1, "live ", 5);
	corewar_putnbr(1, v1);
	corewar_write(1, "\n", 1);
}

char		op_live(t_vm *vm, t_proc *proc)
{
	t_ind	off;
	t_dir	val;
	t_champ	*pl;

	off = 1;
	++vm->total_live;
	proc->last_live = vm->cycles;
	get_dir4(proc, &off, &val);
	if (vm->verbosity & V_OPERATONS)
		out(proc, val);
	if ((pl = get_player(vm, -val)) && (vm->verbosity & V_LIVES))
	{
		corewar_write(1, pl->live_msg, pl->live_msg_size);
		proc->last = pl->id;
		vm->winer = pl;
	}
	move_pc(vm, proc, off);
	return (proc->carry);
}
