/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:40:34 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/09 04:44:39 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_DISABLE_WARNINGS

#include <stdlib.h>
#include "process.h"
#include "arena.h"
#include "ftlib.h"
#include "ftio.h"
#include "vm.h"

static uint32_t	get_next_pid(void)
{
	t_proc			*cur;
	static uint64_t	max = 0;

	if (max > 0xfffffffful)
		max = 0;
	cur = g_procs.head;
	while (cur)
	{
		if (max < cur->pid)
			max = cur->pid;
		cur = cur->next;
	}
	return (++max);
}

t_proc			*add_process(t_ind pc, t_proc *copy)
{
	t_proc	*new;

	if (!(new = ft_memalloc(sizeof(t_proc))))
		exit(ft_print_error("Can't allocate process: %m.\n"));
	if (copy)
		*new = *copy;
	new->prev = NULL;
	if ((new->next = g_procs.head))
		new->next->prev = new;
	g_procs.head = new;
	++g_procs.size;
	new->op = 0;
	new->pid = get_next_pid();
	new->pc = pc % MEM_SIZE;
	if (pc < 0)
		new->pc = MEM_SIZE + new->pc;
	return (new);
}

t_proc			*kill_process(register t_proc *proc)
{
	register t_proc	*res;

	res = proc->next;
	if (proc == g_procs.head)
		g_procs.head = proc->next;
	if (proc->prev)
		proc->prev->next = proc->next;
	if (proc->next)
		proc->next->prev = proc->prev;
	g_procs.size--;
	free(proc);
	return ((t_proc *)res);
}

void			clear_procs(void)
{
	t_proc	*cur;

	cur = g_procs.head;
	while ((cur = g_procs.head))
	{
		g_procs.head = cur->next;
		free(cur);
	}
	g_procs.head = NULL;
	g_procs.tail = NULL;
	g_procs.size = 0;
}

t_byte			move_pc(t_vm *vm, t_proc *proc, const t_ind off)
{
	register int i;

	if (vm->verbosity & V_PC)
	{
		i = 0;
		ft_printf("ADV %d (0x%04x -> 0x%04x) ",
					off, proc->pc, proc->pc + off);
		while (i < off)
			ft_printf("%02x ", g_map[(proc->pc + i++) % MEM_SIZE]);
		ft_printf("\n");
	}
	proc->pc = (proc->pc + off) % MEM_SIZE;
	return (1);
}
