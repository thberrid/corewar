/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 03:06:03 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/07 12:21:51 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "process.h"
# include "vm.h"
# include "op.h"

typedef t_dir	(*t_get_fnc)(t_proc *proc, t_ind *off, t_dir *dest);

t_reg	get_reg(t_proc *proc, t_ind *off, t_reg *dest);
t_dir	get_ind(t_proc *proc, t_ind *off, t_dir *dest);
t_dir	get_dir(t_proc *proc, t_ind *off, t_dir *dest);

void	dir_to_map(t_proc *proc, t_ind off, t_dir val);

t_champ	*get_player(t_vm *vm, uint32_t pid);

static const t_get_fnc	g_getter[] __attribute__((unused)) = {
	0x0, get_reg, get_dir, get_ind
};

t_byte	get_arguments(t_proc *proc, t_args *args);

#endif
