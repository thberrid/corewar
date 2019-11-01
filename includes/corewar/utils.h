/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 03:06:03 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/23 03:07:41 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "process.h"
# include "vm.h"

typedef t_dir	(*t_get_fnc)(t_proc *proc, t_ind *off);

t_reg	get_reg(t_proc *proc, t_ind *off);
t_dir	get_ind(t_proc *proc, t_ind *off);
t_dir	get_dir(t_proc *proc, t_ind *off);

static const t_get_fnc	g_getter[] __attribute__((unused)) = {
	0x0, get_reg, get_dir, get_ind
};

#endif
