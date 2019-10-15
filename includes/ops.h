/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:49:36 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/15 09:55:42 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

char	op_live(void);
char	op_ld(void);
char	op_st(void);
char	op_add(void);
char	op_sub(void);
char	op_and(void);
char	op_or(void);
char	op_xor(void);
char	op_zjmp(void);
char	op_ldi(void);
char	op_sti(void);
char	op_fork(void);
char	op_lld(void);
char	op_lldi(void);
char	op_lfork(void);
char	op_aff(void);

#endif
