/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftfloat.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:47:06 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/20 11:49:00 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTFLOAT_H
# define FTFLOAT_H

# include "ftio/ft_types.h"

# define FT_NAN		(0.0 / 0.0)
# define FT_INF		(1.0 / 0.0)
# define FT_NINF	(-1.0 / 0.0)

t_float		get_float_components(long double ldbl);

#endif
