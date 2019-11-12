/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/12 22:09:21 by abaurens         ###   ########.fr       */
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

static void	out(long int pid, t_dir v1)
{
	write(1, "P     ", ft_max(4.0 - ft_numlen(pid), 0) + 2);
	ft_putlnbr(pid);
	write(1, " | live ", 8);
	ft_putnbr(v1);
	write(1, "\n", 1);
}

static void	live_msg(uint32_t id, const char *name)
{
	write(1, SPLAYER, sizeof(SPLAYER) - 1);
	ft_putnbr(id);
	write(1, LIVEBRAC, sizeof(LIVEBRAC) - 1);
	ft_putstr(name);
	write(1, SALIVE, sizeof(SALIVE) - 1);
}

char		op_live(t_vm *vm, t_proc *proc)
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
		out(proc->pid, val);
	if ((pl = get_player(vm, -val)) && (vm->verbosity & V_LIVES))
	{
		live_msg(pl->pid, pl->name);
		vm->winer = pl;
	}
	move_pc(vm, proc, off);
	return (proc->carry);
}
