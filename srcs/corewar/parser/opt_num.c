/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:34:16 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/05 16:29:38 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm.h"
#include "ftio.h"
#include "ftlib.h"
#include "parser.h"

char	**parse_num(t_vm *vm, char **av)
{
	size_t		i;
	int64_t		v;
	uint32_t	r;

	i = 0;
	if (!*av)
		exit(ft_print_error("Missing value for %s.\n", av[-1]));
	if (!ft_isnumber(*av) || (v = ft_atol(*av)) <= 0 || v > 0xffffffff)
		exit(ft_print_error("Invalid value for %s: '%s'.", av[-1], *av));
	r = (uint32_t)v;
	while (i < vm->psize)
		if (vm->players[i++].pid == r)
			exit(ft_print_error("'%s %d' pid already taken.\n", av[-1], r));
	if (vm->psize < MAX_PLAYERS)
		vm->players[vm->psize].pid = r;
	return (parse_file(vm, av + 1));
}
