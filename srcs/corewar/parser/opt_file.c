/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:34:46 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/02 12:24:29 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm.h"
#include "ftio.h"
#include "ftlib.h"

char	**parse_file(t_vm *vm, char **av)
{
	size_t		i;
	uint32_t	max;

	if (!*av)
		exit(ft_print_error("Missing player file after '-n %u'.\n",
			vm->players[vm->psize].pid));
	if (vm->psize >= MAX_PLAYERS)
		exit(ft_print_error("Can't add '%s': Too many players.\n", *av));
	if (!match(*av, "*.cor"))
		exit(ft_print_error("Invalid file: '%s'.\n", *av));
	vm->players[vm->psize].id = vm->psize;
	vm->players[vm->psize++].pc = (t_byte *)*av;
	if (vm->psize < MAX_PLAYERS)
	{
		i = 0;
		max = vm->players->pid;
		while (++i < vm->psize)
			if (max < vm->players[i].pid)
				max = vm->players[i].pid;
		vm->players[vm->psize].pid = max + 1;
	}
	return (av + 1);
}
