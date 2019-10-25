/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:22:58 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/25 01:31:57 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "config.h"

t_ind	random_indirect(void)
{
	return ((t_ind)(rand() & 0xffff));
}

t_dir	random_direct(void)
{
	return ((t_dir)(rand() & 0xffffffff));
}

t_byte	random_register(void)
{
	return ((t_byte)(((rand() % (REG_NUMBER - 1)) + 1) & 0xff));
}

t_byte	random_byte(void)
{
	return ((t_byte)(rand() & 0xff));
}
