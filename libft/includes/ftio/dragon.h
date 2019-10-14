/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:45:57 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 14:07:32 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAGON_H
# define DRAGON_H

# include <string.h>
# include <stdint.h>

/*
**	# define MASK3			0b111
*/
# define MASK3			7

# define MAX_BINT_BLKS 1000ul
# define MAX_BINT_VALS 0xFFFFFFFF
# define BIT_PER_BLOCK 32

typedef unsigned int	t_block;
typedef unsigned long	t_proc;

typedef struct			s_bint
{
	size_t				len;
	t_block				blks[MAX_BINT_BLKS];
}						t_bint;

t_bint					bi_init(t_bint const
					*const n) __attribute__((visibility("internal")));
char					biiszero(t_bint const
					*const n) __attribute__((visibility("internal")));
void					bi_set(t_bint *n,
					unsigned long val) __attribute__((visibility("internal")));

/*
**	print.c
*/
void					bi_print_dec(t_bint const
					*const n) __attribute__((visibility("internal")));
void					bi_print_bin(t_bint const
					*const n) __attribute__((visibility("internal")));
void					bi_print_bin_space(t_bint const
					*const n) __attribute__((visibility("internal")));

/*
**	bint_cmp.c
*/
long					bicmp(const t_bint *lhs, const
					t_bint *rhs) __attribute__((visibility("internal")));
long					bicmplng(const t_bint *lhs,
					unsigned long v) __attribute__((visibility("internal")));

/*
**	add.c
*/
void					biincrement(
					t_bint *n1) __attribute__((visibility("internal")));
void					biadd(t_bint *res, t_bint *n1,
					t_bint *n2) __attribute__((visibility("internal")));
void					biaddint(t_bint *res, t_bint *n1,
					unsigned int v) __attribute__((visibility("internal")));

/*
**	sub.c
*/
void					bisub(t_bint *res, t_bint *n1,
					t_bint *n2) __attribute__((visibility("internal")));
void					bisubint(t_bint *res, t_bint *n1,
					unsigned int v) __attribute__((visibility("internal")));

/*
**	mul.c
*/
void					bimul(t_bint *res, t_bint *n1,
					t_bint *n2) __attribute__((visibility("internal")));
void					bimulint(t_bint *res, t_bint *n1,
					unsigned int v) __attribute__((visibility("internal")));
void					bimul2(t_bint *res,
					t_bint *n) __attribute__((visibility("internal")));
void					bimul10(t_bint *res,
					t_bint *n) __attribute__((visibility("internal")));

/*
**	pow.c
*/
void					bimul_pow10(t_bint *res, t_bint *n,
					unsigned int ex) __attribute__((visibility("internal")));
void					bipow10(t_bint *const res,
					unsigned int ex) __attribute__((visibility("internal")));
void					bimul_pow10(t_bint *res, t_bint *n,
					unsigned int ex) __attribute__((visibility("internal")));
void					bipow2(t_bint *res,
					unsigned int ex) __attribute__((visibility("internal")));

/*
**	div.c
*/
unsigned int			bidiv_maxq93(t_bint *n1,
					t_bint *n2) __attribute__((visibility("internal")));
unsigned int			bidiv_maxq92(t_bint *n1,
					t_bint *n2) __attribute__((visibility("internal")));
unsigned int			bidiv10(t_bint *res,
					t_bint *n1) __attribute__((visibility("internal")));

/*
**	shift.c
*/
void					bi_shift_left(t_bint *res,
					unsigned int shift) __attribute__((visibility("internal")));

/*
**	utils.c
*/
void					swap(uintptr_t *n1,
					uintptr_t *n2) __attribute__((visibility("internal")));

/*
**	dragon_buffer.c
*/
size_t					add_digit(char **buffer, const size_t l,
					const char c) __attribute__((visibility("internal")));

#endif
