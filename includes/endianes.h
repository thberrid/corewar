/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endianes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 07:26:33 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/15 08:50:03 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENDIANES_H
# define ENDIANES_H

# include <string.h>

void	swap_endianes(void *const val, size_t ln);

enum	e_endianes
{
	FT_LITTLE_ENDIAN,
	FT_BIG_ENDIAN
};

#endif
