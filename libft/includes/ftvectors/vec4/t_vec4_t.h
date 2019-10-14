/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vec4_t.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:12:32 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 19:22:05 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VEC4_T_H
# define T_VEC4_T_H

# include "ftvectors/core/t_vec_t.h"

typedef struct s_vec4i		t_vec4i;
typedef struct s_vec4f		t_vec4f;
typedef struct s_vec4		t_vec4;

struct			s_vec4i
{
	t_int__		x;
	t_int__		y;
	t_int__		z;
	t_int__		w;
};

struct			s_vec4f
{
	t_flt__		x;
	t_flt__		y;
	t_flt__		z;
	t_flt__		w;
};

struct			s_vec4
{
	t_dbl__		x;
	t_dbl__		y;
	t_dbl__		z;
	t_dbl__		w;
};

#endif
