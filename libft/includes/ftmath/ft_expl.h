/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 00:30:17 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/23 07:21:20 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXPL_H
# define FT_EXPL_H

# define LOG2_INTERVALS	7
# define INTERVALS		128
# define BIAS			(LDBL_MAX_EXP - 1)

# define INV_L			1.8466496523378731e+2
# define L1	 			5.4152123484527692e-3
# define L2				-3.2819649005320973e-13

# define A2	 			0.5
# define A3	 			1.6666666666666119e-1
# define A4	 			4.1666666666665887e-2
# define A5	 			8.3333354987869413e-3
# define A6	 			1.3888891738560272e-3

# define HUGE2			0x1p10000L
# define TINY			0x1p-10000L
# define TWOM10000		0x1p-10000L

typedef struct			s_tab
{
	double				hi;
	double				lo;
}						t_tab;

#endif
