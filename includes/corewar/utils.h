/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 03:06:03 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/07 15:31:58 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "process.h"
# include "vm.h"
# include "op.h"

typedef t_byte	(*t_get_fnc)(t_proc *proc, t_ind *off, t_dir *dest);

t_byte	get_reg(t_proc *proc, t_ind *off, t_reg *dest);
t_byte	get_ind(t_proc *proc, t_ind *off, t_dir *dest);
t_byte	get_dir4(t_proc *proc, t_ind *off, t_dir *dest);
t_byte	get_dir2(t_proc *proc, t_ind *off, t_dir *dest);

void	dir_to_map(t_proc *proc, t_ind off, t_dir val);

t_champ	*get_player(t_vm *vm, uint32_t pid);

static const t_get_fnc	g_arg[] __attribute__((unused)) = {
	0x0, get_reg, get_dir4, get_dir2
};

t_byte	get_arguments(t_vm *vm, t_proc *proc, t_args *args);
t_dir	apply_type(t_proc *proc, t_byte type, t_byte mod, t_dir value);

t_byte	move_pc(t_vm *vm, t_proc *proc, const t_ind off);

#endif
