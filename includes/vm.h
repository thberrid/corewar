/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:47:24 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/22 15:51:10 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <inttypes.h>
# include <string.h>
# include <limits.h>
# include "config.h"

# define DUMP_LEN	32

typedef struct s_champ	t_champ;

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
	char		name[PROG_NAME_LENGTH + 1];
};

typedef struct	s_vm
{
	char		dmp_bol;
	uint32_t	dump;
	size_t		psize;
	t_champ		players[MAX_PLAYERS];
}				t_vm;

typedef struct	s_dispatch
{
	const char	*opt;
	char		**(*callback)(t_vm *vm, char **av);
}				t_dispatch;

void			vm_loop(t_vm *vm);
t_vm			parse_args(char **av);
void			destruct(void) __attribute__((destructor));

#endif
