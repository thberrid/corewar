/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_dump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:32:38 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/05 17:01:26 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "ftlib.h"
#include "ftio.h"
#include "vm.h"

char	**parse_dump(t_vm *vm, char **av)
{
	int64_t	v;

	if (vm->dmp_bol)
		exit(ft_print_error("Doubled dump cycle.\n"));
	if (!*av)
		exit(ft_print_error("Missing value for %s.\n", av[-1]));
	if (!ft_isnumber(*av) || (v = ft_atol(*av)) < 0 || v > 0xffffffff)
		exit(ft_print_error("Invalid value for %s: '%s'.", av[-1], *av));
	vm->dmp_bol = 1;
	vm->dump = (uint32_t)v;
	return (av + 1);
}

char	**parse_zaz_dump(t_vm *vm, char **av)
{
	av = parse_dump(vm, av);
	vm->dmp_bol = 2;
	return (av);
}
