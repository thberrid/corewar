/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:18:27 by baurens           #+#    #+#             */
/*   Updated: 2019/12/02 16:26:22 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include <string.h>
# include "process.h"
# include "config.h"

# define FOO 42u

extern t_byte	g_map[MEM_SIZE];

void			map_to_var(void *dest, t_ind pos, register size_t size);
void			var_to_map(t_proc *p, void *s, t_ind ps, register size_t size);
void			write_byte(t_proc *proc, int pos, t_byte val);
void			vm_dump(uint32_t dump_len);

#endif
