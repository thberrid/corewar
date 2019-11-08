/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 07:24:26 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/08 23:27:01 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "ftlib.h"
#include "ftio.h"
#include "vm.h"

t_byte		g_map[MEM_SIZE];
t_lst		g_procs;

t_champ		*get_player(t_vm *vm, uint32_t pid)
{
	uint32_t	i;
	t_champ		*p;

	i = 0;
	p = vm->players;
	while (i++ < vm->psize)
	{
		if (p->pid == pid)
			return (p);
		p++;
	}
	return (NULL);
}

void		destruct(void)
{
	clear_procs();
}

int			main(int ac __attribute__((unused)), char **av)
{
	size_t	i;
	t_vm	vm;

	i = 0;
	ft_bzero(&g_procs, sizeof(t_lst));
	parse_args(&vm, av + 1);
	ft_putstr("Introducing contestants...\n");
	while (i < vm.psize)
	{
		ft_printf("* Player %u, weighing %zu bytes, \"%s\" (\"%s\") !\n",
				vm.players[i].pid, vm.players[i].size,
				vm.players[i].name, vm.players[i].comm);
		++i;
	}
	vm_loop(&vm);
	ft_printf(WINMSG, vm.winer->pid, vm.winer->name);
	return (0);
}
