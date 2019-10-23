/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/23 02:26:55 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "config.h"
#include "arena.h"
#include "vm.h"
#include "op.h"
#include "ftio.h"

char	op_and(t_vm *vm, t_proc *proc)
{
	t_byte	ocp;
	t_ind	off;

	(void)vm;
	(void)proc;
	ocp = g_map[proc->pc + 1 % MEM_SIZE];
	if ((off = check_ocp(ocp, OP_STI)) && (proc->pc += off))
		return (proc->carry);
	off = 2;
	ft_printf("code: %u - and\n", OP_AND);
	return (0);
}
