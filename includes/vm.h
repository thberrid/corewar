/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:47:24 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/15 11:19:33 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <inttypes.h>
# include "op.h"

/*
**	id:		position in the champion tab
**	num:	id number for the battle
**	path:	path to the file
*/

typedef struct	s_champ
{
	uint32_t	id;
	uint32_t	num;
	char		*path;
}				t_champ;

void			parse_args(int ac, char **av);

#endif
