/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ubinary.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:52:40 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/01 15:15:36 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UBINARY_H
# define UBINARY_H

# include "ftio/ft_types.h"

/*
**	len.c
*/
char				*short_binary(t_printf *const data, t_arg *const arg);
char				*short_short_binary(t_printf *const data, t_arg *const arg);
char				*long_binary(t_printf *const data, t_arg *const arg);
char				*long_long_binary(t_printf *const data, t_arg *const arg);

/*
**	exotic.c
*/
char				*intmax_binary(t_printf *const data, t_arg *const arg);
char				*size_binary(t_printf *const data, t_arg *const arg);
char				*ssize_binary(t_printf *const data, t_arg *const arg);
char				*ptrdiff_binary(t_printf *const data, t_arg *const arg);
char				*quad_binary(t_printf *const data, t_arg *const arg);

#endif
