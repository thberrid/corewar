/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:47:24 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/20 22:07:39 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <inttypes.h>
# include <string.h>
# include <limits.h>
# include "op.h"

# define DUMP_LEN	32

/*
**	fd:		filedescriptor to the opened file
**	id:		position in the champion tab
**	num:	id number for the battle
*/

typedef struct	s_champ
{
	int			fd;
	uint32_t	id;
	uint32_t	pid;
}				t_champ;

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

t_vm			parse_args(char **av);

#endif
