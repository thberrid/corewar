/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:47:24 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/03 17:51:08 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <inttypes.h>
# include <string.h>
# include <limits.h>
# include "config.h"

# define DUMP_LEN	32
# define VERBOSITY	(4 | 32)

typedef struct s_champ	t_champ;

# define V_LIVES		1
# define V_CYCLES		2
# define V_OPERATONS	4
# define V_DEATHS		8
# define V_PC			16
# define V_AFF			32

typedef enum	e_dumpm
{
	NONE, SUBJECT, ZAZ
}				t_dumpm;

/*
**	pc:		startpoint of the player in the arena
**	id:		position in the champion tab
**	pid:	process id (used by live during the battle)
*/
struct			s_champ
{
	t_byte		*pc;
	uint32_t	id;
	uint32_t	pid;
	size_t		size;
	char		name[PROG_NAME_LENGTH + 1];
	char		comm[COMMENT_LENGTH + 1];
};

typedef struct	s_vm
{
	t_dumpm		dmp_bol;
	uint32_t	dump;
	size_t		psize;
	t_champ		players[MAX_PLAYERS];
	t_byte		verbosity;
}				t_vm;

typedef struct	s_dispatch
{
	const char	*opt;
	char		**(*callback)(t_vm *vm, char **av);
}				t_dispatch;

void			vm_loop(t_vm *vm);
t_vm			parse_args(char **av);
void			destruct(void) __attribute__((destructor));

/*
**	vm ocp functions
*/
t_ind			check_ocp(t_byte ocp, uint32_t opid);
t_ind			get_arg_size(t_byte ocp, uint32_t opid);

#endif