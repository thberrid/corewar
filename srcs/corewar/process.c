/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:40:34 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/03 02:59:13 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_DISABLE_WARNINGS

#include <stdlib.h>
#include "process.h"
#include "output.h"
#include "arena.h"
#include "ftlib.h"
#include "ftio.h"
#include "vm.h"

static uint64_t	get_next_pid(char *buf)
{
	int				i;
	static uint64_t	max = 0;

	++max;
	i = 1 + (max >= 10) + (max >= 100) + (max >= 1000);
	ft_lunbrcat(buf + (4 - i), max);
	return (max);
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
	new->pc = pc % MEM_SIZE;
	ft_bzero(new->name + 6, 10);
	ft_memcpy(new->name, "P     ", 6);
	new->pid = get_next_pid(new->name + 2);
	ft_strcat(new->name, " | ");
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
	if (!res)
		g_procs.tail = NULL;
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
	if (vm->verbosity & V_PC)
		out_pc(proc, off);
	proc->pc = (proc->pc + off) % MEM_SIZE;
	return (1);
}
