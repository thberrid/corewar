/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vec2_f.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:08:11 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 19:22:43 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VEC2_F_H
# define T_VEC2_F_H

# include "ftvectors/vec2/t_vec2_t.h"

t_dbl__		v2_norm(t_vec2 *v);
t_flt__		v2f_norm(t_vec2f *v);
t_dbl__		v2i_norm(t_vec2i *v);
t_flt__		v2i_normf(t_vec2i *v);

t_vec2		v2_addv(t_vec2 *v1, t_vec2 *v2);
t_vec2i		v2i_addv(t_vec2i *v1, t_vec2i *v3);
t_vec2f		v2f_addv(t_vec2f *v1, t_vec2f *v2);

t_vec2		v2_subv(t_vec2 *v1, t_vec2 *v2);
t_vec2i		v2i_subv(t_vec2i *v1, t_vec2i *v2);
t_vec2f		v2f_subv(t_vec2f *v1, t_vec2f *v2);

t_vec2		v2_mulv(t_vec2 *v1, t_vec2 *v2);
t_vec2i		v2i_mulv(t_vec2i *v1, t_vec2i *v2);
t_vec2f		v2f_mulv(t_vec2f *v1, t_vec2f *v2);

t_vec2		v2_add1(t_vec2 *v, t_dbl__ i);
t_vec2i		v2i_add1(t_vec2i *v, t_int__ i);
t_vec2f		v2f_add1(t_vec2f *v, t_flt__ i);

t_vec2		v2_sub1(t_vec2 *v, t_dbl__ i);
t_vec2i		v2i_sub1(t_vec2i *v, t_int__ i);
t_vec2f		v2f_sub1(t_vec2f *v, t_flt__ i);

t_vec2		v2_mul1(t_vec2 *v, t_dbl__ i);
t_vec2i		v2i_mul1(t_vec2i *v, t_int__ i);
t_vec2f		v2f_mul1(t_vec2f *v, t_flt__ i);

t_vec2		v2_div1(t_vec2 *v, t_dbl__ i);
t_vec2i		v2i_div1(t_vec2i *v, t_int__ i);
t_vec2f		v2f_div1(t_vec2f *v, t_flt__ i);

t_vec2		v2_addc(t_vec2 *v, uint32_t c, ...);
t_vec2i		v2i_addc(t_vec2i *v, uint32_t c, ...);
t_vec2f		v2f_addc(t_vec2f *v, uint32_t c, ...);

t_vec2		v2_subc(t_vec2 *v, uint32_t c, ...);
t_vec2i		v2i_subc(t_vec2i *v, uint32_t c, ...);
t_vec2f		v2f_subc(t_vec2f *v, uint32_t c, ...);

t_vec2		v2_mulc(t_vec2 *v, uint32_t c, ...);
t_vec2i		v2i_mulc(t_vec2i *v, uint32_t c, ...);
t_vec2f		v2f_mulc(t_vec2f *v, uint32_t c, ...);

t_vec2		v2_normalize(t_vec2 *v);
t_vec2i		v2i_normalize(t_vec2i *v);
t_vec2f		v2f_normalize(t_vec2f *v);

t_dbl__		v2_dot(t_vec2 *v1, t_vec2 *v2);
t_dbl__		v2i_dot(t_vec2i *v1, t_vec2i *v2);
t_flt__		v2f_dot(t_vec2f *v1, t_vec2f *v2);

t_vec2		v2_cross(t_vec2 *u);
t_vec2i		v2i_cross(t_vec2i *u);
t_vec2f		v2f_cross(t_vec2f *u);

#endif
