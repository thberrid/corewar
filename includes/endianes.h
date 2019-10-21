/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endianes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 07:26:33 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/21 12:03:00 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENDIANES_H
# define ENDIANES_H

# include <string.h>

# define DEPRECATION_MSG	"use 'system_to_bin' or 'bin_to_system' instead"

void		swap_endianes(void *const val,
				size_t ln) __attribute__((deprecated(DEPRECATION_MSG)));
static void	system_to_bin(void *const val,
				size_t ln) __attribute__((unused,weakref("swap_endianes")));
static void	bin_to_system(void *const val,
				size_t ln) __attribute__((unused,weakref("swap_endianes")));

enum	e_endianes
{
	FT_LITTLE_ENDIAN,
	FT_BIG_ENDIAN
};

#endif
