/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:53:12 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 14:13:49 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CORE_H
# define FT_CORE_H

# include "ftio/ft_types.h"
# include "ftio/ft_bigfloat.h"

# define LEN_MD			"qjzZtlLh"
# define LEN_MD_CHRS	" qjzZtlLhH"

# define BIN	"01"
# define OCTA	"01234567"
# define DECI	"0123456789"
# define HEXA	"0123456789abcdef"

/*
**	va_lst_cpy.c
*/
void		save_va_list(va_list *save,
					va_list ap) __attribute__((visibility("internal")));

/*
**	core.c
*/
int			get_non_arg(const char *format,
					t_printf *data) __attribute__((visibility("internal")));
int			parse_conversion(const char **format,
					t_printf *data) __attribute__((visibility("internal")));

/*
**	buffer.c
*/
char		*insert_buffer(t_printf *const data, const char *str,
							size_t len) __attribute__((visibility("internal")));

/*
**	flags.c
*/
char		flag(t_arg *arg, char mask) __attribute__((visibility("internal")));

/*
**	args.c
*/
int			parse_arg(const char **format, t_printf *data,
					t_arg *arg) __attribute__((visibility("internal")));

/*
**	list_manager.c
*/
void		clear_list(t_ftlist *lst) __attribute__((visibility("internal")));

/*
**	argument_manager.c
*/
int			get_arg_a(t_printf *data, const size_t idx,
						t_arg *a) __attribute__((visibility("internal")));
int			get_arg_i(t_printf *data, const size_t idx,
						int *v) __attribute__((visibility("internal")));

/*
**	printf_lltoa.c
*/
char		chtoa_base(register char *dest, unsigned char v,
					const char *b) __attribute__((visibility("internal")));
char		*printf_lltoa(long int nb,
					const int min) __attribute__((visibility("internal")));
char		*padded_lltoa(long nb, const int min_d, const int pad,
								char r) __attribute__((visibility("internal")));
char		*padded_ulltoa(unsigned long nb, const int min_d, const int pad,
								char r) __attribute__((visibility("internal")));
char		*padded_ulltoa_bin(unsigned long nb, const int min_d, const int pad,
								char r) __attribute__((visibility("internal")));
char		*padded_ulltoa_octal(unsigned long nb, const int min_d,
				const int pad, char r) __attribute__((visibility("internal")));
char		*padded_ulltoa_hexa(unsigned long nb, const int min_d,
				const int pad, char r) __attribute__((visibility("internal")));

/*
**	unicode.c
*/
size_t		ft_wstrlen(
				const wchar_t *wstr) __attribute__((visibility("internal")));
size_t		ft_wchar_len(
				const wchar_t chr) __attribute__((visibility("internal")));
size_t		wchartochars(char *dst,
				wchar_t c) __attribute__((visibility("internal")));
char		*ft_wstrtostr(char *dst,
				const wchar_t *src) __attribute__((visibility("internal")));

/*
**	ft_ldtoa.c
*/
char		*ft_ldtoa(long double d) __attribute__((visibility("internal")));
char		*exp_dbl(long double d,
				size_t prec) __attribute__((visibility("internal")));
char		*exp_dbl_hex(long double d, int prec,
				t_bool lng) __attribute__((visibility("internal")));

/*
**	floating_point.c
*/
t_bflt		*get_mantissa(t_float *f) __attribute__((visibility("internal")));
long double	dbl_abs(long double *d,
					char *sign) __attribute__((visibility("internal")));
t_float		get_float_components(
				long double d) __attribute__((visibility("internal")));

/*
**	bankers_round.c
*/
char		*banker_round(char *val, const size_t prec,
				const char *base) __attribute__((visibility("internal")));

/*
**	float_round.c
*/
char		ldbl_num(long double d) __attribute__((visibility("internal")));
char		*round_hex(char *val, size_t prec,
					int *exp) __attribute__((visibility("internal")));
char		*round_tabflt(char *val, size_t prec,
					int *exp) __attribute__((visibility("internal")));

/*
**	big_num.c
*/
char		*to_hex(t_bflt *deci) __attribute__((visibility("internal")));
t_bflt		*new_ftobflt(long double d) __attribute__((visibility("internal")));

/*
**	double_floating.c
*/
char		*printf_ldbl(t_printf *const data,
					t_arg *const arg) __attribute__((visibility("internal")));

#endif
