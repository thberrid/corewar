/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <smoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 06:05:50 by smoreno-          #+#    #+#             */
/*   Updated: 2019/11/07 04:00:42 by thberrid         ###   ########.fr       */
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
	int					cflag;
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
int						ft_errors(int err, int line_n);

/*
** tools
*/

void					instruct_display(t_instruct *this);
void					instruct_display_all(t_instruct_head *head, t_header *header);
int						ft_usage(void);
t_instruct				*add_inst(t_instruct_head *head);
int						debug_instruct(char *line, t_instruct_head *head); 
int						is_paramtype_allowed(char param_type, t_instruct *inst, int i);
int						get_paramlen(int opcode);
int						is_strn_valid(char *str, int n);
int						update_progsize(t_instruct_head *head, t_instruct *inst);
int						get_octet(t_byte id, char param_type);
int						default_op(t_instruct *inst);
#endif
