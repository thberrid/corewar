/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:01:15 by baurens           #+#    #+#             */
/*   Updated: 2019/10/22 15:53:38 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "arena.h"
#include "ftio.h"
#include "vm.h"

void	vm_dump(void)
{
	register size_t	i;
	register t_byte	*p;

	i = 0;
	p = g_map;
	while (i++ < MEM_SIZE)
		ft_printf("%02x%c", *p++, (i % DUMP_LEN ? ' ' : '\n'));
	exit(0);
}
