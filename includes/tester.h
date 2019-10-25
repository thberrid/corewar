/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:28:11 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/25 02:55:11 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include "config.h"
# include "op.h"

# define TEST_PER_CASES	(1)
# define TEST_DIR		"tests"

# define FT_DISABLE_WARNINGS

typedef struct s_tst	t_tst;

struct		s_tst
{
	uint8_t	a[4];
};

t_byte		random_byte(void);
t_dir		random_direct(void);
t_ind		random_indirect(void);
t_byte		random_register(void);

void		gen_file(const char *dir, const t_op *op, int i, t_tst *state);

#endif
