/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:53:40 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/25 19:26:21 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "arena.h"
#include "vm.h"

void	write_byte(t_proc *proc, int pos, t_byte val)
{
	float r;
	float g;
	float b;

	r = 0.0;
	g = 0.0;
	b = 0.0;
	g_map[pos] = val;
	if (GRAPHIC)
	{
		if (proc->last == 0)
			g = 1.0f;
		else if (proc->last == 1)
			r = 1.0f;
		else if (proc->last == 2)
			b = 1.0f;
		else
		{
			g = 1.0f;
			b = 1.0f;
		}
		set_color(pos, r, g, b);
	}
}
