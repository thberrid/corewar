/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpmath.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:46:55 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 14:01:55 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPMATH_H
# define FPMATH_H

# include <inttypes.h>

# if (defined(__APPLE__) || defined(__MACH__))
#  include <machine/endian.h>
# else
#  include <endian.h>
# endif

# ifdef __arm__
#  if (defined(__VFP_FP__) || defined(__ARM_EABI__))
#   define IEEE_WORD_ORDER	BYTE_ORDER
#  else
#   define IEEE_WORD_ORDER	BIG_ENDIAN
#  endif
# else
#  define IEEE_WORD_ORDER	BYTE_ORDER
# endif

typedef union		u_ieee_float_shape_type
{
	float			value;
	unsigned int	word;
}					t_ieee_float_shape_type;

typedef union		u_ieee_double_shape_type
{
	double			value;
	struct
	{
# if (IEEE_WORD_ORDER == BIG_ENDIAN)

		uint32_t	msw;
		uint32_t	lsw;
# else

		uint32_t	lsw;
		uint32_t	msw;
# endif

	}				parts;
	struct
	{
		uint64_t	w;
	}				xparts;
}					t_ieee_double_shape_type;

typedef union		u_ieeel2bits
{
	long double		e;
	struct
	{
		uint32_t	manl	:32;
		uint32_t	manh	:32;
		uint32_t	exp		:15;
		uint32_t	sign	:1;
		uint32_t	junkl	:16;
		uint32_t	junkh	:32;
	}				bits;
	struct
	{
		uint64_t	man		:64;
		uint32_t	expsign	:16;
		uint64_t	junk	:48;
	}				xbits;
}					t_ieeel2bits;

typedef struct		s_tab1
{
	float			g;
	float			f_hi;
	double			f_lo;
}					t_tab1;

typedef struct		s_tab2
{
	float			h;
	float			e;
}					t_tab2;

/*
**	fp32math.c
*/
float				set_float_word(
						uint32_t val) __attribute__((visibility("internal")));
uint32_t			get_float_word(
						float x) __attribute__((visibility("internal")));

/*
**	fp64maath.c
*/
uint32_t			get_low_word(
						double x) __attribute__((visibility("internal")));
uint32_t			get_high_word(
						double x) __attribute__((visibility("internal")));
void				insert_word(double *d, uint32_t high,
						uint32_t low) __attribute__((visibility("internal")));

/*
**	fp80math.c
*/
t_ieeel2bits		ld80c(uint64_t m, uint16_t ex,
						long double v) __attribute__((visibility("internal")));
void				set_ldbl_expsign(long double *x,
						uint16_t exp) __attribute__((visibility("internal")));
void				extract_ldbl80_word(long double x, uint16_t *exp,
						uint64_t *man) __attribute__((visibility("internal")));

/*
**	ft_rem_pio2.c
*/
int					ft_rem_pio2(double x,
						double *y) __attribute__((visibility("internal")));

#endif
