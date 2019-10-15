/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endianes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 07:23:53 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/15 08:41:22 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "endianes.h"
#include "ftio.h"

/*
**	BIG ENDIAN:
**	uint16_t v = 1 => 0x0001
**	(uint8_t *)&v => | 0x00 | 0x01 |
**	*((uint8_t *)&v) => 0x00
**
**	LITTLE ENDIAN
**	uint16_t v = 1 => 0x0100
**	(uint8_t *)&v => | 0x01 | 0x00 |
**	*((uint8_t *)&v) => 0x01
*/

static inline char	get_endianes(void)
{
	volatile const uint16_t	v = 1;

	return (*((uint8_t *)&v) == 0);
} __attribute__((always_inline))

void				swap_endianes(void *const ptr, register size_t ln)
{
	char *const		val = ptr;
	register size_t	j;
	char			t;

	if (get_endianes() == FT_BIG_ENDIAN)
		return ;
	j = 0;
	while (ln-- > j)
	{
		t = val[ln];
		val[ln] = val[j];
		val[j++] = t;
	}
}
