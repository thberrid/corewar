/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 06:05:50 by smoreno-          #+#    #+#             */
/*   Updated: 2019/10/19 05:18:56 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include <stdlib.h>
#include "op.h"
//#include "ftlib.h"
#include "../../libft/includes/ftlib.h"
#include "../../libft/includes/ftio.h"

typedef struct 	s_instruc
{
	struct s_instruc 	*next;
	struct s_instruc 	*prev;
	char				*label;
	char				id;
	uint32_t			plabel;
	t_arg_type			ocp;
	uint32_t			parms[3];
	size_t				len;
} 				t_instruct;

typedef struct 	s_instruc_head
{
	t_instruct	*head;
	size_t		length;
	size_t		slen;
} 				t_instruct_head;

int		ft_read(t_instruct_head *head, char *path, t_header *header);
int		check_instruct(char *line, t_instruct_head *head);

/*
**
*/

void	clean_struct(t_instruct_head *head);

#endif
