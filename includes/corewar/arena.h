/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:18:27 by baurens           #+#    #+#             */
/*   Updated: 2019/11/02 18:00:58 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include <string.h>
# include "config.h"

extern t_byte	g_map[MEM_SIZE];

void			map_to_var(void *dest, t_ind pos, register size_t size);
void			var_to_map(void *src, t_ind pos, register size_t size);

void			vm_dump(uint32_t dump_len);

#endif
