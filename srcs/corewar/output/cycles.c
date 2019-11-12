/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:18:52 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/12 19:11:05 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftio.h"
#include "vm.h"

void	out_ctd(t_scycle ctd)
{
	write(1, "Cycle to die is now ", 20);
	ft_putlnbr(ctd);
	write(1, "\n", 1);
}

void	out_cycles(t_cycle cycle)
{
	write(1, "It is now cycle ", 16);
	ft_putunbr(cycle);
	write(1, "\n", 1);
}
