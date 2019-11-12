/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:19:10 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/12 22:41:07 by abaurens         ###   ########.fr       */
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

static char	*addr_to_hex(char *buf, t_ind nb)
{
	buf[3] = VM_HEXA[nb & 15];
	buf[2] = VM_HEXA[(nb >> 4) & 15];
	buf[1] = VM_HEXA[(nb >> 8) & 15];
	buf[0] = VM_HEXA[(nb >> 12) & 15];
	return (buf);
}

/*
**	max offset = 18 (4 * direct + ocp + opcode)
**	such offset gives "00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 "
**	which is 54 bytes long
*/

void		out_pc(t_proc *proc, const t_ind off)
{
	register int	i;
	char			tmp;
	char			bytes[20 + 54];

	i = 0;
	write(1, "ADV ", 4);
	ft_putnbr(off);
	ft_memcpy(bytes, " (0x0000 -> 0x0000) ", 20);
	addr_to_hex(bytes + 4, proc->pc);
	addr_to_hex(bytes + 14, proc->pc + off);
	while (i < off)
	{
		tmp = g_map[(proc->pc + i) % MEM_SIZE];
		bytes[20 + i * 3 + 0] = VM_HEXA[(tmp >> 4) & 15];
		bytes[20 + i * 3 + 1] = VM_HEXA[tmp & 15];
		bytes[20 + i * 3 + 2] = ' ';
		++i;
	}
	write(1, bytes, 20 + off * 3);
	write(1, "\n", 1);
}
