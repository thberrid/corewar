/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:51:41 by baurens           #+#    #+#             */
/*   Updated: 2019/11/08 22:39:35 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# ifdef VM_TEST
#  include "test_funcs.h"
# endif
# ifdef VM
#  include "process.h"
#  include "vm.h"
# endif
# include "config.h"

typedef struct s_op		t_op;
typedef struct s_args	t_args;

struct		s_op
{
	char	*name;
	int		arg_cnt;
	t_byte	args[MAX_ARGS_NUMBER];
	int		id;
	int		cost;
	char	*desc;
	char	ocp;
	char	hdir;
	char	(*fnc)();
};

struct		s_args
{
	t_byte	t1;
	t_byte	t2;
	t_byte	t3;
	t_byte	t4;
	t_dir	v1;
	t_dir	v2;
	t_dir	v3;
	t_dir	v4;
};

enum	e_opcode
{
	OP_NOP,
	OP_LIVE,
	OP_LD,
	OP_ST,
	OP_ADD,
	OP_SUB,
	OP_AND,
	OP_OR,
	OP_XOR,
	OP_ZJMP,
	OP_LDI,
	OP_STI,
	OP_FORK,
	OP_LLD,
	OP_LLDI,
	OP_LFORK,
	OP_AFF,
	UNKNOWN
};

# ifdef VM
#  define OP_LIVE_F		op_live
#  define OP_LD_F		op_ld
#  define OP_ST_F		op_st
#  define OP_ADD_F		op_add
#  define OP_SUB_F		op_sub
#  define OP_AND_F		op_and
#  define OP_OR_F		op_or
#  define OP_XOR_F		op_xor
#  define OP_ZJMP_F		op_zjmp
#  define OP_LDI_F		op_ldi
#  define OP_STI_F		op_sti
#  define OP_FORK_F		op_fork
#  define OP_LLD_F		op_lld
#  define OP_LLDI_F		op_lldi
#  define OP_LFORK_F	op_lfork
#  define OP_AFF_F		op_aff

char		op_or(t_vm *vm, t_proc *proc);
char		op_st(t_vm *vm, t_proc *proc);
char		op_ld(t_vm *vm, t_proc *proc);
char		op_add(t_vm *vm, t_proc *proc);
char		op_sub(t_vm *vm, t_proc *proc);
char		op_and(t_vm *vm, t_proc *proc);
char		op_xor(t_vm *vm, t_proc *proc);
char		op_aff(t_vm *vm, t_proc *proc);
char		op_sti(t_vm *vm, t_proc *proc);
char		op_ldi(t_vm *vm, t_proc *proc);
char		op_lld(t_vm *vm, t_proc *proc);
char		op_lldi(t_vm *vm, t_proc *proc);
char		op_zjmp(t_vm *vm, t_proc *proc);
char		op_live(t_vm *vm, t_proc *proc);
char		op_fork(t_vm *vm, t_proc *proc);
char		op_lfork(t_vm *vm, t_proc *proc);

# else
#  ifdef VM_TEST
#   define OP_LIVE_F	test_live
#   define OP_LD_F		test_ld
#   define OP_ST_F		test_st
#   define OP_ADD_F		test_add
#   define OP_SUB_F		test_sub
#   define OP_AND_F		test_and
#   define OP_OR_F		test_or
#   define OP_XOR_F		test_xor
#   define OP_ZJMP_F	test_zjmp
#   define OP_LDI_F		test_ldi
#   define OP_STI_F		test_sti
#   define OP_FORK_F	test_fork
#   define OP_LLD_F		test_lld
#   define OP_LLDI_F	test_lldi
#   define OP_LFORK_F	test_lfork
#   define OP_AFF_F		test_aff
#  else
#   define OP_LIVE_F	0
#   define OP_LD_F		0
#   define OP_ST_F		0
#   define OP_ADD_F		0
#   define OP_SUB_F		0
#   define OP_AND_F		0
#   define OP_OR_F		0
#   define OP_XOR_F		0
#   define OP_ZJMP_F	0
#   define OP_LDI_F		0
#   define OP_STI_F		0
#   define OP_FORK_F	0
#   define OP_LLD_F		0
#   define OP_LLDI_F	0
#   define OP_LFORK_F	0
#   define OP_AFF_F		0
#  endif
# endif

/*
**	CARRY CHANGER
**		with values labeled as opcode [v1[, v2[, v3[, v4]]]]
**
**			live	no
**			ld		yes : carry = !v1
**			st		no
**			add		yes : carry = !(v1 + v2)
**			sub		yes : carry = !(v1 - v2)
**			and		yes : carry = !(v1 & v2)
**			or		yes : carry = !(v1 | v2)
**			xor		yes : carry = !(v1 ^ v2)
**			zjmp	no
**			ldi		no
**			sti		no
**			fork	no
**			lld		yes : carry = !(v1)
**			lldi	yes : carry = !(*((pc + (v1 + v2)) % MEM_SIZE))
**			lfork	no
**			aff		no
*/

static const t_op	g_op_tab[] __attribute__((unused)) =
{
	{"nop", 0, {0}, 0, 0, "nothing", 0, 0, 0x0},
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, OP_LIVE_F},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, OP_LD_F},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, OP_ST_F},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, OP_ADD_F},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, OP_SUB_F},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, OP_AND_F},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, OP_OR_F},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, OP_XOR_F},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, OP_ZJMP_F},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, OP_LDI_F},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, OP_STI_F},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, OP_FORK_F},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, OP_LLD_F},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, OP_LLDI_F},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, OP_LFORK_F},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, OP_AFF_F},
	{0, 0, {0}, 0, 0, 0, 0, 0, 0x0}
};

#endif
