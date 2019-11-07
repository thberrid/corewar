/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:11:35 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/07 13:14:47 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "arena.h"
#include "ftio.h"
#include "op.h"

t_byte	get_arguments(t_proc *proc, t_args *args)
{
	t_byte		err;
	t_byte		ocp;
	t_ind		off;
	const t_op	*cur;

	err = 0;
	cur = g_op_tab;
	while (cur->name && cur->id != g_map[proc->pc % MEM_SIZE])
		++cur;
	ocp = g_map[proc->pc + 1 % MEM_SIZE];
	if ((off = check_ocp(ocp, cur->id)) && (proc->pc += off))
		return (0);
	off = 2;
	if (cur->arg_cnt > 0)
		err |= g_getter[args->t1 = ((ocp >> 6) & 3)](proc, &off, &(args->v1));
	if (cur->arg_cnt > 1)
		err |= g_getter[args->t2 = ((ocp >> 4) & 3)](proc, &off, &(args->v2));
	if (cur->arg_cnt > 2)
		err |= g_getter[args->t3 = ((ocp >> 2) & 3)](proc, &off, &(args->v3));
	if (cur->arg_cnt > 3)
		err |= g_getter[args->t4 = (ocp & 3)](proc, &off, &(args->v4));
	if (err)
		proc->pc += off;
	return ((!err) * off);
}
