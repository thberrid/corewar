/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_mgr.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:22:04 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 14:02:56 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENT_MGR_H
# define ARGUMENT_MGR_H

# include "ftio/ft_types.h"

t_val	get_pointer(va_list *ap,
			const int l) __attribute__((visibility("internal")));
t_val	get_double(va_list *ap,
			const int l) __attribute__((visibility("internal")));
t_val	get_integer(va_list *ap,
			const int l) __attribute__((visibility("internal")));

#endif
