/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:19:10 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/12 19:48:38 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "process.h"
#include "config.h"
#include "ftmath.h"
#include "arena.h"
#include "ftlib.h"
#include "ftio.h"

static	char	*addr_to_hex(char *buf, t_ind nb)
{
	buf[3] = "0123456789abcdef"[nb % 16];
	buf[2] = "0123456789abcdef"[(nb / 16) % 16];
	buf[1] = "0123456789abcdef"[(nb / 16 / 16) % 16];
	buf[0] = "0123456789abcdef"[(nb / 16 / 16 / 16) % 16];
	return (buf);
}

void	out_pc(t_proc *proc, const t_ind off)
{
	register int	i;
	char			tmp[20];
	char			byt[3];

	byt[2] = ' ';
	write(1, "ADV ", 4);
	ft_putnbr(off);
	ft_memcpy(tmp, " (0x0000 -> 0x0000) ", 20);
	addr_to_hex(tmp + 4, proc->pc);
	addr_to_hex(tmp + 14, proc->pc + off);
	write(1, tmp, 20);
	i = 0;
	while (i < off)
	{
		byt[0] = "0123456789abcdef"[g_map[(proc->pc + i) % MEM_SIZE] / 16];
		byt[1] = "0123456789abcdef"[g_map[(proc->pc + i++) % MEM_SIZE] % 16];
		write(1, byt, 3);
	}
	write(1, "\n", 1);
}
