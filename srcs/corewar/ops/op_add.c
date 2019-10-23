/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:04:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/22 17:38:55 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "config.h"
#include "vm.h"
#include "op.h"
#include "ftio.h"

char	op_add(t_vm *vm, t_proc *proc)
{
	(void)vm;
	(void)proc;
	ft_printf("code: %u - add\n", OP_ADD);
	return (0);
}
