/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <smoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 06:05:50 by smoreno-          #+#    #+#             */
/*   Updated: 2019/11/01 20:07:27 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include "endianes.h"
# include "ftlib.h"
# include "ftio.h"
# include "config.h"
# include "op.h"

# define REG_CHAR "0123456789"

typedef struct			s_instruc
{
	struct s_instruc	*next;
	struct s_instruc	*prev;
	char				*label;
	t_byte				id;
	uint32_t			plabel;
	uint32_t			byt_index;
	t_arg_type			ocp;
	char				*params_str[3];
	uint32_t			params_bits[3];
	size_t				len;
	int					line_n;
}						t_instruct;

typedef struct			s_instruc_head
{
	t_instruct			*head;
	size_t				length;
	size_t				slen;
	int					line;
}						t_instruct_head;

/*
** parsing
*/

int						ft_read(t_instruct_head *head, char *path,
									t_header *header);
int						check_instruct(char *line, t_instruct_head *head);

/*
** free
*/

void					instruct_free(t_instruct_head *head);
void					ft_errors(int err, int line_n);

/*
** tools
*/

void					ft_bprint_fd(void *ptr, int nbits, int fd);
void					ft_bprint_fd_rev(void *ptr, int nbits, int fd);
void					instruct_display(t_instruct *this);
void					instruct_display_all(t_instruct_head *head);

#endif
