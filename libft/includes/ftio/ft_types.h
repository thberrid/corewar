/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:29:02 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/25 10:14:50 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# include <time.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stddef.h>
# include <inttypes.h>
# include <sys/types.h>

# define ERROR	-1

/*
**	# define F_MINS	0b00000001
**	# define F_ZERO	0b00000010
**	# define F_PLUS	0b00000100
**	# define F_SPAC	0b00001000
**	# define F_HASH	0b00010000
**	# define F_COLO	0b00100000
*/
# define F_MINS	1
# define F_ZERO	(1 << 1)
# define F_PLUS	(1 << 2)
# define F_SPAC	(1 << 3)
# define F_HASH	(1 << 4)
# define F_COLO	(1 << 5)
# define FLAGS_V "-0+ #'"
# define FLAG_C 6

# ifdef __STDC_VERSION__
#  define UQUAD_TYPE	u_quad_t
#  define QUAD_TYPE		quad_t
#  define ULLI_TYPE 	unsigned long long int
#  define LLI_TYPE		long long int
# else
#  define UQUAD_TYPE	uint32_t
#  define ULLI_TYPE 	uint64_t
#  define QUAD_TYPE		int32_t
#  define LLI_TYPE 		int64_t
# endif

typedef struct s_printf	t_printf;
typedef struct s_arg	t_arg;
typedef struct tm		t_tm;

/*
**	special types
*/
typedef UQUAD_TYPE		t_uquad;
typedef QUAD_TYPE		t_quad;
typedef ULLI_TYPE		t_ull;
typedef LLI_TYPE		t_ll;

# undef UQUAD_TYPE
# undef QUAD_TYPE
# undef ULLI_TYPE
# undef LLI_TYPE

typedef enum			e_bool
{
	FALSE,
	TRUE,
	MAYBE
}						t_bool;

typedef enum			e_arg_type
{
	ARG_INT,
	ARG_PTR,
	ARG_FLT,
	ARG_NON
}						t_arg_type;

typedef struct			s_float
{
	unsigned char		sign;
	int					exponent;
	unsigned long int	mantissa;
}						t_float;

typedef union			u_float_conv
{
	long double			value;
	unsigned char		bytes[sizeof(long double)];
}						t_float_conv;

typedef struct			s_converter
{
	char				c;
	t_bool				w_arg;
	t_arg_type			t;
	char				*(*func)(t_printf *data, t_arg *arg);
}						t_converter;

typedef union			u_val
{
	void				*p;
	double				f;
	long double			lf;
	t_ll				i;
}						t_val;

struct					s_arg
{
	t_converter			conv;
	t_val				val;
	size_t				flag_idx;
	size_t				prec_idx;
	size_t				min_idx;
	char				flags;
	int					min;
	int					prec;
	int					length_modifier;
};

typedef struct			s_lst_elem
{
	t_val				val;
	struct s_lst_elem	*next;
	struct s_lst_elem	*prev;
}						t_lst_elem;

typedef struct			s_ftlist
{
	t_lst_elem			*head;
	t_lst_elem			*tail;
	size_t				size;
}						t_ftlist;

struct					s_printf
{
	t_bool				use_chain_format;
	size_t				arg_count;
	t_val				*vals;
	size_t				len;
	t_ftlist			args;
	char				*buf;
	int					err;
	va_list				va_lst;
};

#endif
