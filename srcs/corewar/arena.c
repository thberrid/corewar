/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:01:15 by baurens           #+#    #+#             */
/*   Updated: 2019/11/25 19:18:36 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "endianes.h"
#include "arena.h"
#include "ftlib.h"
#include "ftio.h"
#include "vm.h"

void	vm_dump(const uint32_t dump_len)
{
	register size_t	i;
	register t_byte	*p;

	i = 0;
	p = g_map;
	while (i++ < MEM_SIZE)
	{
		if (!(i - 1) || !((i - 1) % dump_len))
			ft_printf("0x%04lx : ", i - 1);
		ft_printf("%02x %s", *p++, (i % dump_len ? "" : "\n"));
	}
	exit(0);
}

void	map_to_var(void *dest, t_ind pos, register size_t size)
{
	const	size_t s = size;

	while (size-- > 0)
		((t_byte *)dest)[size] = g_map[(pos + size) % MEM_SIZE];
	bin_to_system(dest, s);
}

void	var_to_map(t_proc *proc, void *src, t_ind pos, register size_t size)
{
	system_to_bin(src, size);
	while (size-- > 0)
		write_byte(proc, (pos + size) % MEM_SIZE, ((t_byte *)src)[size]);
}
