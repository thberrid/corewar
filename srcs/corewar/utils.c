/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 02:51:55 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/05 16:01:59 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "endianes.h"
#include "process.h"
#include "arena.h"
#include "op.h"
#include "ftio.h"

t_reg	get_reg(t_proc *proc, t_ind *off)
{
	t_byte	reg;

	reg = g_map[(proc->pc + *off) % MEM_SIZE];
	if (reg <= 0 || reg > REG_NUMBER)
		return (0);
	(*off)++;
	return (proc->regs[reg - 1]);
}

t_dir	get_dir__(t_proc *proc, t_ind *off, char hdir)
{
	t_dir	dir;
	t_ind	ind;
	void	*v;

	dir = 0;
	ind = 0;
	v = &dir;
	if (hdir)
		v = &ind;
	map_to_var(v, proc->pc + *off, DIR_SIZE / (hdir + 1));
	/*bin_to_system(v, DIR_SIZE / (hdir + 1));*/
	(*off) += DIR_SIZE / (hdir + 1);
	return (hdir ? ind : dir);
}

t_dir	get_dir(t_proc *proc, t_ind *off)
{
	return (get_dir__(proc, off, g_op_tab[g_map[proc->pc % MEM_SIZE]].hdir));
}

t_dir	get_ind(t_proc *proc, t_ind *off)
{
	t_ind	addr;

	addr = (g_map[(proc->pc + *off) % MEM_SIZE] << 8)
		| g_map[(proc->pc + *off + 1) % MEM_SIZE];
	(*off) += 2;
	addr = (addr % IDX_MOD);
	return (get_dir__(proc, &addr, 0));
}

void	dir_to_map(t_proc *proc, t_ind off, t_dir val)
{
	var_to_map(&val, (proc->pc + off), sizeof(val));
}
