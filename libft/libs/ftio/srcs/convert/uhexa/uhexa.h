/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uhexa.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:56:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/01 15:15:44 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UHEXA_H
# define UHEXA_H

# include "ftio/ft_types.h"

/*
**	len.c
*/
char				*short_hexa(t_printf *const data, t_arg *const arg);
char				*short_short_hexa(t_printf *const data, t_arg *const arg);
char				*long_hexa(t_printf *const data, t_arg *const arg);
char				*long_long_hexa(t_printf *const data, t_arg *const arg);

/*
**	exotic.c
*/
char				*intmax_hexa(t_printf *const data, t_arg *const arg);
char				*size_hexa(t_printf *const data, t_arg *const arg);
char				*ssize_hexa(t_printf *const data, t_arg *const arg);
char				*ptrdiff_hexa(t_printf *const data, t_arg *const arg);
char				*quad_hexa(t_printf *const data, t_arg *const arg);

#endif
