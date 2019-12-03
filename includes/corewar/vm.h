/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:47:24 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/03 02:45:39 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# ifndef GRAPHIC
#  define GRAPHIC	0
# endif

# include <inttypes.h>
# include <string.h>
# include <limits.h>
# include "config.h"

typedef signed long		t_scycle;
typedef unsigned int	t_cycle;
typedef struct s_champ	t_champ;

# define V_LIVES		1
# define V_CYCLES		2
# define V_OPERATONS	4
# define V_DEATHS		8
# define V_PC			16
# define V_AFF			32

# define OUT_BUF_SIZE	4096
# define BUFF_TRESHOLD	1

extern char	g_buff[OUT_BUF_SIZE];
extern int	g_pos;

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
	char		live_msg[PROG_NAME_LENGTH + 55];
	int			live_msg_size;
};

typedef struct	s_vm
{
	char		dmp_bol;
	int32_t		last_check;
	uint32_t	dump;
	size_t		psize;
	uint32_t	total_live;
	t_champ		players[MAX_PLAYERS];
	t_byte		verbosity;
	t_scycle	last_dec;
	t_scycle	cycle_to_die;
	t_cycle		cycles;
	t_champ		*winer;
}				t_vm;

void			cycle(t_vm *vm);
char			vm_loop(t_vm *vm);

/*
**	graphic functions
*/
char			graphic_loop(t_vm *vm);
void			set_color(int pos, float r, float g, float b);

void			parse_args(t_vm *vm, char **av);
void			destruct(void) __attribute__((destructor));

/*
**	vm ocp functions
*/
t_byte			check_ocp(t_byte ocp, uint32_t opid, t_ind *off);
t_ind			get_arg_size(t_byte ocp, uint32_t opid);

void			destruct(void) __attribute__((destructor));

#endif
