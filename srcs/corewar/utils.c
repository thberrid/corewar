/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 02:51:55 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/26 16:31:32 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "endianes.h"
#include "process.h"
#include "arena.h"
#include "op.h"
#include "ftio.h"

t_byte	get_reg(t_proc *proc, t_ind *off, t_reg *dest)
{
	*dest = g_map[(proc->pc + (*off)++) % MEM_SIZE];
	if (*dest <= 0 || *dest > REG_NUMBER)
		return (1);
	return (0);
}

t_byte	get_dir2(t_proc *proc, t_ind *off, t_dir *dest)
{
	t_ind	ind;

	ind = 0;
	map_to_var(&ind, proc->pc + *off, sizeof(ind));
	*off += sizeof(ind);
	*dest = ind;
	return (0);
}

t_byte	get_dir4(t_proc *proc, t_ind *off, t_dir *dest)
{
	if (g_op_tab[proc->op].hdir)
		return (get_dir2(proc, off, dest));
	map_to_var(dest, proc->pc + *off, sizeof(*dest));
	*off += sizeof(*dest);
	return (0);
}

t_byte	get_ind(t_proc *proc, t_ind *off, t_dir *dest)
{
	t_ind	addr;

	addr = (g_map[(proc->pc + *off) % MEM_SIZE] << 8)
		| g_map[(proc->pc + *off + 1) % MEM_SIZE];
	(*off) += 2;
	addr = (addr % IDX_MOD);
	get_dir4(proc, &addr, dest);
	return (0);
}

void	dir_to_map(t_proc *proc, t_ind off, t_dir val)
{
	var_to_map(proc, &val, (proc->pc + off), sizeof(val));
}
