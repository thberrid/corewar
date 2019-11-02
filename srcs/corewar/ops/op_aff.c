/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/02 18:04:09 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

char	op_aff(t_vm *vm, t_proc *proc)
{
	(void)vm;
	(void)proc;
	ft_printf("code: %u - aff\n", OP_AFF);
	return (0);
}
