/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigfloat.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 06:22:45 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 14:08:52 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIGFLOAT_H
# define FT_BIGFLOAT_H

# include <string.h>

typedef unsigned char	t_digit;

typedef struct		s_bflt
{
	unsigned char	neg;
	t_digit			*ent;
	t_digit			*dec;
	size_t			entl;
	size_t			decl;
	size_t			len;
}					t_bflt;

typedef t_bflt		t_bfloat;

t_bflt				*new_bflt(
			const char *value) __attribute__((visibility("internal")));
t_bflt				*set_bflt(
		t_bflt *num, const char *value) __attribute__((visibility("internal")));
t_bflt				*copy_bflt(
			t_bflt const *const num) __attribute__((visibility("internal")));
void				unset_bflt(
			t_bflt *const num) __attribute__((visibility("internal")));
void				del_bflt(
			t_bflt const *const num) __attribute__((visibility("internal")));

char				*bflt_tostr(
			t_bflt const *const num) __attribute__((visibility("internal")));
void				print_bflt(
			t_bflt const *const num) __attribute__((visibility("internal")));

void				*abort_bflt(t_bflt const *const to_abort,
						char step) __attribute__((visibility("internal")));

t_bflt				*add_bflt(t_bflt const *const a,
				t_bflt const *const b) __attribute__((visibility("internal")));
t_bflt				*mul_bflt(t_bflt const *const a,
				t_bflt const *const b) __attribute__((visibility("internal")));
t_bflt				*pow_bflt(t_bflt const *const a,
				t_bflt const *const b) __attribute__((visibility("internal")));

#endif
