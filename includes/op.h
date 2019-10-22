/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:51:41 by baurens           #+#    #+#             */
/*   Updated: 2019/10/22 16:26:22 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include "process.h"
# include "config.h"
# include "vm.h"

typedef struct s_op	t_op;

struct		s_op
{
	char	*name;
	int		arg_cnt;
	char	args[4];
	int		id;
	int		cost;
	char	*desc;
	char	ocp;
	char	hdir;
	char	(*fnc)(t_vm *vm, t_proc *proc);
};

# ifdef VM
#  define OP_LIVE	op_live
#  define OP_LD		op_ld
#  define OP_ST		op_st
#  define OP_ADD	op_add
#  define OP_SUB	op_sub
#  define OP_AND	op_and
#  define OP_OR		op_or
#  define OP_XOR	op_xor
#  define OP_ZJMP	op_zjmp
#  define OP_LDI	op_ldi
#  define OP_STI	op_sti
#  define OP_FORK	op_fork
#  define OP_LLD	op_lld
#  define OP_LLDI	op_lldi
#  define OP_LFORK	op_lfork
#  define OP_AFF	op_aff

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
#  define OP_LIVE	0
#  define OP_LD		0
#  define OP_ST		0
#  define OP_ADD	0
#  define OP_SUB	0
#  define OP_AND	0
#  define OP_OR		0
#  define OP_XOR	0
#  define OP_ZJMP	0
#  define OP_LDI	0
#  define OP_STI	0
#  define OP_FORK	0
#  define OP_LLD	0
#  define OP_LLDI	0
#  define OP_LFORK	0
#  define OP_AFF	0
# endif

static const t_op	g_op_tab[] __attribute__((unused)) =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, OP_LIVE},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, OP_LD},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, OP_ST},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, OP_ADD},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, OP_SUB},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, OP_AND},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, OP_OR},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, OP_XOR},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, OP_ZJMP},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, OP_LDI},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, OP_STI},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, OP_FORK},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, OP_LLD},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, OP_LLDI},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, OP_LFORK},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, OP_AFF},
	{0, 0, {0}, 0, 0, 0, 0, 0, 0x0}
};

#endif
