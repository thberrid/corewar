/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:51:41 by baurens           #+#    #+#             */
/*   Updated: 2019/10/15 08:24:54 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include <inttypes.h>

# define REG_CODE			1
# define DIR_CODE			2
# define IND_CODE			3

# define MAX_ARGS_NUMBER	4
# define MAX_PLAYERS		4
# define MEM_SIZE			(4*1024)
# define IDX_MOD			(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)

# define COMMENT_CHAR		'#'
# define LABEL_CHAR			':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','

# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

# define REG_NUMBER			16

# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		50
# define NBR_LIVE			21
# define MAX_CHECKS			10

# define T_REG				1
# define T_DIR				2
# define T_IND				4
# define T_LAB				8

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3

# define IND_SIZE			2
# define REG_SIZE			4
# define DIR_SIZE			REG_SIZE

typedef uint16_t			t_ind;
typedef uint32_t			t_reg;
typedef t_reg				t_dir;
typedef t_ind				t_hdir;
typedef uint8_t				t_byte;
typedef char				t_arg_type;

typedef struct	s_header
{
	uint32_t	magic;
	char		prog_name[PROG_NAME_LENGTH + 1];
	uint32_t	prog_size;
	char		comment[COMMENT_LENGTH + 1];
}				t_header;

typedef struct	s_op
{
	char		*name;
	int			arg_cnt;
	char		args[4];
	int			id;
	int			cost;
	char		*desc;
	char		ocp;
	char		hdir;
	char		(*fnc)(void);
}				t_op;
/*
**	(t_proc *process, char *mem);
*/

#endif