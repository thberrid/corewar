/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftvector.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:52:22 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 19:24:05 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTVECTOR_H
# define FTVECTOR_H

# include "ftvectors/t_vec2.h"
# include "ftvectors/t_vec3.h"
# include "ftvectors/t_vec4.h"

t_vec2	vec2(t_dbl__ x, t_dbl__ y);
t_vec2i	vec2i(t_int__ x, t_int__ y);
t_vec2f	vec2f(t_flt__ x, t_flt__ y);

t_vec2	init_vec2(t_vec2 *v, uint32_t c, ...);
t_vec2i	init_vec2i(t_vec2i *v, uint32_t c, ...);
t_vec2f	init_vec2f(t_vec2f *v, uint32_t c, ...);

t_vec3	vec3(t_dbl__ x, t_dbl__ y, t_dbl__ z);
t_vec3i	vec3i(t_int__ x, t_int__ y, t_int__ z);
t_vec3f	vec3f(t_flt__ x, t_flt__ y, t_flt__ z);

t_vec3	init_vec3(t_vec3 *v, uint32_t c, ...);
t_vec3i	init_vec3i(t_vec3i *v, uint32_t c, ...);
t_vec3f	init_vec3f(t_vec3f *v, uint32_t c, ...);

t_vec4	vec4(t_dbl__ x, t_dbl__ y, t_dbl__ z, t_dbl__ w);
t_vec4i	vec4i(t_int__ x, t_int__ y, t_int__ z, t_int__ w);
t_vec4f	vec4f(t_flt__ x, t_flt__ y, t_flt__ z, t_flt__ w);

t_vec4	init_vec4(t_vec4 *v, uint32_t c, ...);
t_vec4i	init_vec4i(t_vec4i *v, uint32_t c, ...);
t_vec4f	init_vec4f(t_vec4f *v, uint32_t c, ...);

#endif
