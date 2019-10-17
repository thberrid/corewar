/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 07:24:26 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/17 19:00:07 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftlib.h"
#include "ftio.h"
#include "vm.h"

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
		ft_printf("  fd:  %d\n", vm->players[i].fd);
		if (i < vm->psize)
			close(vm->players[i].fd);
		++i;
	}
}

int			main(int ac __attribute__((unused)), char **av)
{
	t_vm	vm;

	vm = parse_args(av + 1);
	print_vm_state(&vm);
	return (0);
}
