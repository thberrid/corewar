/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_funcs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:41:32 by baurens           #+#    #+#             */
/*   Updated: 2019/10/30 17:54:05 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_FUNCS_H
# define TEST_FUNCS_H

char		test_or();
char		test_st();
char		test_ld();
char		test_add();
char		test_sub();
char		test_and();
char		test_xor();
char		test_aff();
char		test_sti();
char		test_ldi();
char		test_lld();
char		test_lldi();
char		test_zjmp();
char		test_live();
char		test_fork();
char		test_lfork();

#  undef	OP_LIVE_F
#  define	OP_LIVE_F	test_live
#  undef	OP_LD_F
#  define	OP_LD_F		test_ld
#  undef	OP_ST_F
#  define	OP_ST_F		test_st
#  undef	OP_ADD_F
#  define	OP_ADD_F	test_add
#  undef	OP_SUB_F
#  define	OP_SUB_F	test_sub
#  undef	OP_AND_F
#  define	OP_AND_F	test_and
#  undef	OP_OR_F
#  define	OP_OR_F		test_or
#  undef	OP_XOR_F
#  define	OP_XOR_F	test_xor
#  undef	OP_ZJMP_F
#  define	OP_ZJMP_F	test_zjmp
#  undef	OP_LDI_F
#  define	OP_LDI_F	test_ldi
#  undef	OP_STI_F
#  define	OP_STI_F	test_sti
#  undef	OP_FORK_F
#  define	OP_FORK_F	test_fork
#  undef	OP_LLD_F
#  define	OP_LLD_F	test_lld
#  undef	OP_LLDI_F
#  define	OP_LLDI_F	test_lldi
#  undef	OP_LFORK_F
#  define	OP_LFORK_F	test_lfork
#  undef	OP_AFF_F
#  define	OP_AFF_F	test_aff

#endif
