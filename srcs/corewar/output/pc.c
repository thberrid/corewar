/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:19:10 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/02 14:41:02 by abaurens         ###   ########.fr       */
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

void		out_pc(t_proc *proc, register t_ind off)
{
	register int	i;
	register int	j;
	register char	out[82];
	char			tmp;

	j = proc->pc;
	i = (off >= 10);
	ft_memcpy(out, "ADV ", 4);
	ft_nbrcat(out + 4, off);
	ft_memcpy(out + 5 + i, " (0x0000 -> 0x0000) ", 20);
	addr_to_hex(out + 9 + i, j);
	addr_to_hex(out + 19 + i, j + off);
	off = off * 3 + i;
	while (i < off)
	{
		tmp = g_map[j % MEM_SIZE];
		out[25 + i] = VM_HEXA[(tmp >> 4) & 15];
		out[26 + i] = VM_HEXA[tmp & 15];
		out[27 + i] = ' ';
		i += 3;
		++j;
	}
	out[25 + i] = '\n';
	write(1, out, 26 + i);
}
