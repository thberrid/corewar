/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 07:24:26 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/15 08:33:06 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_DISABLE_WARNINGS

#include "endianes.h"
#include "ftio.h"
#include "op.h"

int		main(void)
{
	int	i;

	i = COREWAR_EXEC_MAGIC;
	ft_printf("%#010x\n", i);
	swap_endianes(&i, sizeof(i));
	ft_printf("%#010x\n", i);
	swap_endianes(&i, sizeof(i));
	ft_printf("%#010x\n", i);
	ft_printf("Corewar\n");
	return (0);
}
