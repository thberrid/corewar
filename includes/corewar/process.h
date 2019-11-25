/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:57:27 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/25 19:15:14 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include <string.h>
# include "config.h"

typedef struct s_proc	t_proc;
typedef struct s_lst	t_lst;

struct			s_proc
{
	int			op;
	uint16_t	pc;
	long int	pid;
	uint32_t	last;
	t_byte		carry;
	uint32_t	lives;
	uint32_t	last_live;
	int			time_to_wait;
	t_reg		regs[REG_NUMBER];
	t_proc		*next;
	t_proc		*prev;
};

struct			s_lst
{
	size_t		size;
	t_proc		*head;
	t_proc		*tail;
};

t_proc			*add_process(t_ind pc, t_proc *copy);
t_proc			*kill_process(t_proc *proc);
void			clear_procs(void);

extern t_lst	g_procs;

#endif
