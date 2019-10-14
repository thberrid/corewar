/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:53:50 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 14:05:59 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# include "ftio/ft_types.h"

/*
**	convert/
*/
char	*convert_percent(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_integer(t_printf *const data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_linteger(t_printf *const data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_u_integer(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_u_linteger(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_u_integer_octal(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_u_linteger_octal(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_u_integer_hexa(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_double_floating(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_double_scientific(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_double_compact(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_double_hexa(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_char(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_wchar(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_string(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_wstring(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_wide_char_string(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_pointer(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_length(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_strerror(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_u_integer_binary(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_non_printable_string(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_non_printable_char(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));
char	*convert_iso_date(t_printf *data,
			t_arg *const arg) __attribute__((visibility("internal")));

/*
**	double_scientific.c
*/
char	*printf_ldbl_s(t_arg *const ar) __attribute__((visibility("internal")));

/*
**	double_floating.c
*/
char	*printf_ldbl(t_printf *const data,
			t_arg *const arg) __attribute__((visibility("internal")));

/*
**	% = only print a percent char
**		(because % is used to escape conversions) (NO ARG)
**	i, d = signed decimal
**	o = unsigned octal
**	u = unsigned decimal
**	x, X = unsigned hexadecimal (low and up case)
**	f = double (and floats casted to double)
**	F = double (and floats casted to double) but NAN and INFINITY are upcase
**	e = double (and floats casted to double) but printd in the form xxxxe+-yyy
**	E = same as e but the exposant letter 'e' is upcase
**	g = the most compact between f and e
**	G = same as g but between f and E
**	a = double (and floats casted to double) in lowcase hexadecimal
**		with the form [-]0xh.hhhhp+-dd
**	A = double (and floats casted to double) in upcase hexadecimal
**		with the form [-]0Xh.hhhhP+-dd (same as a, but X and P are upcase)
**	c = 1 byte character
**	C = wide character (wchar)
**	s = 1 byte character string
**	S = wide character string
**	p = pointer address (in hexadecimal format)
**	n = place the number of character writed by this printf until this
**		convertion into an int pointer
**	b = unsigned binary
**		(prefixed with 0b with flag #)
**	r = like %s but output the hex vlaue preceeded by a backslash
**		for non-printable charcters (# flag uses the decimal format)
**	R = like %c but output the hex vlaue preceeded by a backslash
**		for non-printable charcters (# flag uses the decimal format)
**	k = ISO formated date (ls formated with flag #)
**	m = prints the value of strerror(errno) (NO ARG)
*/

static const t_converter	g_converters[] =
{
	{'%', FALSE, ARG_NON, convert_percent},
	{'d', TRUE, ARG_INT, convert_integer},
	{'D', TRUE, ARG_INT, convert_linteger},
	{'i', TRUE, ARG_INT, convert_integer},
	{'u', TRUE, ARG_INT, convert_u_integer},
	{'U', TRUE, ARG_INT, convert_u_linteger},
	{'o', TRUE, ARG_INT, convert_u_integer_octal},
	{'O', TRUE, ARG_INT, convert_u_linteger_octal},
	{'x', TRUE, ARG_INT, convert_u_integer_hexa},
	{'X', TRUE, ARG_INT, convert_u_integer_hexa},
	{'f', TRUE, ARG_FLT, convert_double_floating},
	{'F', TRUE, ARG_FLT, convert_double_floating},
	{'e', TRUE, ARG_FLT, convert_double_scientific},
	{'E', TRUE, ARG_FLT, convert_double_scientific},
	{'g', TRUE, ARG_FLT, convert_double_compact},
	{'G', TRUE, ARG_FLT, convert_double_compact},
	{'a', TRUE, ARG_FLT, convert_double_hexa},
	{'A', TRUE, ARG_FLT, convert_double_hexa},
	{'c', TRUE, ARG_INT, convert_char},
	{'C', TRUE, ARG_INT, convert_wchar},
	{'s', TRUE, ARG_PTR, convert_string},
	{'S', TRUE, ARG_PTR, convert_wstring},
	{'p', TRUE, ARG_PTR, convert_pointer},
	{'n', TRUE, ARG_PTR, convert_length},
	{'b', TRUE, ARG_INT, convert_u_integer_binary},
	{'r', TRUE, ARG_PTR, convert_non_printable_string},
	{'R', TRUE, ARG_INT, convert_non_printable_char},
	{'m', FALSE, ARG_NON, convert_strerror},
	{'k', TRUE, ARG_INT, convert_iso_date},
	{'\0', MAYBE, ARG_NON, (void *)0x0}
};

#endif
