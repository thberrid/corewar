/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vec2_t.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:01:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 19:22:33 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VEC2_T_H
# define T_VEC2_T_H

# include "ftvectors/core/t_vec_t.h"

typedef struct s_vec2i	t_vec2i;
typedef struct s_vec2f	t_vec2f;
typedef struct s_vec2	t_vec2;

struct			s_vec2i
{
	t_int__		x;
	t_int__		y;
};

struct			s_vec2f
{
	t_flt__		x;
	t_flt__		y;
};

struct			s_vec2
{
	t_dbl__		x;
	t_dbl__		y;
};

#endif
