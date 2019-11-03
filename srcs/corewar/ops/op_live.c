/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/03 23:11:30 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

char	op_live(t_vm *vm, t_proc *proc)
{
	size_t	i;
	t_ind	off;
	t_dir	val;

	off = 1;
	proc->lives++;
	proc->last_live = vm->cycles;
	val = get_dir(proc, &off);
	if (vm->verbosity & V_OPERATONS)
		ft_printf("P %4d | live %d\n", proc->pid, val);
	proc->pc += off;
	i = 0;
	while (i < vm->psize)
		if (vm->players[i++].pid == (uint32_t)val)
			break;
	if (i <= vm->psize && vm->verbosity & V_LIVES)
	{
		ft_printf("Player %d (%s) is said to be alive\n", -val,
			vm->players[i - 1].name);
		vm->winer = vm->players[i - 1].id;
	}
	return (proc->carry);
}
