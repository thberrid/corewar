/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vec4_f.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:08:11 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 19:21:52 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VEC4_F_H
# define T_VEC4_F_H

# include "ftvectors/vec4/t_vec4_t.h"

/*
**	norm computation
*/
t_dbl__		v4_norm(t_vec4 *v);
t_flt__		v4f_norm(t_vec4f *v);

t_dbl__		v4i_norm(t_vec4i *v);
t_flt__		v4i_normf(t_vec4i *v);
/*
**	vector to vector operations
*/
t_vec4		v4_addv(t_vec4 *v1, t_vec4 *v2);
t_vec4i		v4i_addv(t_vec4i *v1, t_vec4i *v4);
t_vec4f		v4f_addv(t_vec4f *v1, t_vec4f *v2);

t_vec4		v4_subv(t_vec4 *v1, t_vec4 *v2);
t_vec4i		v4i_subv(t_vec4i *v1, t_vec4i *v2);
t_vec4f		v4f_subv(t_vec4f *v1, t_vec4f *v2);

t_vec4		v4_mulv(t_vec4 *v1, t_vec4 *v2);
t_vec4i		v4i_mulv(t_vec4i *v1, t_vec4i *v2);
t_vec4f		v4f_mulv(t_vec4f *v1, t_vec4f *v2);

/*
**	scalar to vector operations
*/
t_vec4		v4_add1(t_vec4 *v, t_dbl__ i);
t_vec4i		v4i_add1(t_vec4i *v, t_int__ i);
t_vec4f		v4f_add1(t_vec4f *v, t_flt__ i);

t_vec4		v4_sub1(t_vec4 *v, t_dbl__ i);
t_vec4i		v4i_sub1(t_vec4i *v, t_int__ i);
t_vec4f		v4f_sub1(t_vec4f *v, t_flt__ i);

t_vec4		v4_mul1(t_vec4 *v, t_dbl__ i);
t_vec4i		v4i_mul1(t_vec4i *v, t_int__ i);
t_vec4f		v4f_mul1(t_vec4f *v, t_flt__ i);

t_vec4		v4_div1(t_vec4 *v, t_dbl__ i);
t_vec4i		v4i_div1(t_vec4i *v, t_int__ i);
t_vec4f		v4f_div1(t_vec4f *v, t_flt__ i);

/*
**	decomposed vector to vector operation
*/
t_vec4		v4_addc(t_vec4 *v, uint32_t c, ...);
t_vec4i		v4i_addc(t_vec4i *v, uint32_t c, ...);
t_vec4f		v4f_addc(t_vec4f *v, uint32_t c, ...);

t_vec4		v4_subc(t_vec4 *v, uint32_t c, ...);
t_vec4i		v4i_subc(t_vec4i *v, uint32_t c, ...);
t_vec4f		v4f_subc(t_vec4f *v, uint32_t c, ...);

t_vec4		v4_mulc(t_vec4 *v, uint32_t c, ...);
t_vec4i		v4i_mulc(t_vec4i *v, uint32_t c, ...);
t_vec4f		v4f_mulc(t_vec4f *v, uint32_t c, ...);

/*
**	normalization operation
*/
t_vec4		v4_normalize(t_vec4 *v);
t_vec4i		v4i_normalize(t_vec4i *v);
t_vec4f		v4f_normalize(t_vec4f *v);

/*
**	dot product operation
*/
t_dbl__		v4_dot(t_vec4 *v1, t_vec4 *v2);
t_dbl__		v4i_dot(t_vec4i *v1, t_vec4i *v2);
t_flt__		v4f_dot(t_vec4f *v1, t_vec4f *v2);

/*
**	cross product operation
*/
t_vec4		v4_cross(t_vec4 *v1, t_vec4 *v2, t_vec4 *v3);
t_vec4i		v4i_cross(t_vec4i *v1, t_vec4i *v2, t_vec4i *v3);
t_vec4f		v4f_cross(t_vec4f *v1, t_vec4f *v2, t_vec4f *v3);

#endif
