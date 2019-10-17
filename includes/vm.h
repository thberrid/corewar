/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:47:24 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/17 08:31:03 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <inttypes.h>
# include <limits.h>
# include "op.h"

# define DUMP_FLG	"-dump"
# define NUM_FLG	"-n"

/*
**	id:		position in the champion tab
**	num:	id number for the battle
**	path:	path to the file
*/

typedef struct	s_champ
{
	uint32_t	id;
	uint32_t	num;
	char		path[PATH_MAX];
}				t_champ;

void			parse_args(int ac, char **av);

#endif
