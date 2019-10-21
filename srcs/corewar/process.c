/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:40:34 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/21 13:28:40 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "process.h"
#include "ftlib.h"
#include "ftio.h"
#include "vm.h"

t_proc	*add_process(t_ind pc, t_proc *copy)
{
	t_proc	*new;

	if (!(new = ft_memalloc(sizeof(t_proc))))
		exit(ft_print_error("Can't allocate process: %m.\n"));
	if (copy)
		*new = *copy;
	new->pc = pc;
	new->prev = NULL;
	if ((new->next = g_procs.head))
		new->next->prev = new;
	g_procs.head = new;
	g_procs.size++;
	return (new);
}

void	kill_process(t_proc *proc)
{
	if (proc == g_procs.head)
		g_procs.head = proc->next;
	if (proc->prev)
		proc->prev->next = proc->next;
	if (proc->next)
		proc->next->prev = proc->prev;
	g_procs.size--;
	free(proc);
}

void	clear_procs(void)
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
