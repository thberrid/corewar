/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:19:10 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/03 03:43:51 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "process.h"
#include "output.h"
#include "config.h"
#include "ftmath.h"
#include "arena.h"
#include "ftlib.h"
#include "ftio.h"

void		write_hex(t_ind nb)
{
	corewar_putchar(1, VM_HEXA[(nb >> 12) & 15]);
	corewar_putchar(1, VM_HEXA[(nb >> 8) & 15]);
	corewar_putchar(1, VM_HEXA[(nb >> 4) & 15]);
	corewar_putchar(1, VM_HEXA[nb & 15]);
}

void		out_pc(t_proc *proc, register t_ind off)
{
	register int	j;
	char			tmp;

	j = proc->pc;
	corewar_write(1, "ADV ", 4);
	corewar_putnbr(1, off);
	corewar_write(1, " (0x", 4);
	write_hex(j);
	corewar_write(1, " -> 0x", 6);
	write_hex(j + off);
	corewar_write(1, ") ", 2);
	while (off-- > 0)
	{
		tmp = g_map[j++ % MEM_SIZE];
		corewar_putchar(1, VM_HEXA[(tmp >> 4) & 15]);
		corewar_putchar(1, VM_HEXA[tmp & 15]);
		corewar_putchar(1, ' ');
	}
	corewar_putchar(1, '\n');
}
