/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:31:58 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/01 15:15:30 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LENGTH_H
# define LENGTH_H

# include "ftio/ft_types.h"

/*
**	len.c
*/
char			*short_length(t_printf *const data, t_arg *const arg);
char			*short_short_length(t_printf *const data, t_arg *const arg);
char			*long_length(t_printf *const data, t_arg *const arg);
char			*long_long_length(t_printf *const data, t_arg *const arg);

/*
**	exotic.h
*/
char			*intmax_length(t_printf *const data, t_arg *const arg);
char			*size_length(t_printf *const data, t_arg *const arg);
char			*ssize_length(t_printf *const data, t_arg *const arg);
char			*ptrdiff_length(t_printf *const data, t_arg *const arg);
char			*quad_length(t_printf *const data, t_arg *const arg);

#endif
