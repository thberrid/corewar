/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 07:24:26 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/21 00:54:03 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "arena.h"
#include "ftlib.h"
#include "ftio.h"
#include "vm.h"

t_byte	g_map[MEM_SIZE];

__attribute__((unused))
static void	print_vm_state(t_vm *vm)
{
	size_t	i;

	i = 0;
	ft_printf("dump:   %u\n", vm->dump);
	ft_printf("players: %zu\n", vm->psize);
	while (i < MAX_PLAYERS)
	{
		ft_printf("champ[%zu]:\n", i);
		ft_printf("  id:  %u\n", vm->players[i].id);
		ft_printf("  pid: %08x (%u)\n", vm->players[i].pid, vm->players[i].pid);
		++i;
	}
}

int			main(int ac __attribute__((unused)), char **av)
{
	t_vm	vm;

	vm = parse_args(av + 1);
	print_vm_state(&vm);
	vm_dump();
	return (0);
}
