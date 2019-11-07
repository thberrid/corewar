/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_verbosity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:25:45 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/07 21:07:45 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftlib.h"
#include "ftio.h"
#include "vm.h"

char	**parse_verbosity(t_vm *vm, char **av)
{
	size_t		i;
	int64_t		v;
	t_byte		ref;

	i = 0;
	ref = (V_OPERATONS | V_CYCLES | V_DEATHS | V_LIVES | V_PC);
	if (!*av)
		exit(ft_print_error("Missing value for %s.\n", av[-1]));
	if (!ft_isnumber(*av) || (v = ft_atoi(*av)) < 0 || v > ref)
		exit(ft_print_error("Invalid value for %s: '%s'.", av[-1], *av));
	vm->verbosity |= v;
	return (av + 1);
}
