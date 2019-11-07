/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:54:53 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/07 21:03:35 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "arena.h"
#include "op.h"

static const t_ind	g_vlen[4] = {
	0, 1, REG_SIZE, IND_SIZE,
};

static const t_byte	g_ocpc[4] = {
	0, T_REG, T_DIR, T_IND
};

t_ind	get_arg_size(t_byte ocp, uint32_t opid)
{
	if (ocp == DIR_CODE && g_op_tab[opid].hdir)
		--ocp;
	return (g_vlen[ocp]);
}

t_byte	check_ocp(t_byte ocp, uint32_t opid, t_ind *off)
{
	int				i;
	t_ind			ln;
	t_byte			cr;
	t_byte			rs;
	const t_byte	*ref;

	i = 0;
	ln = 0;
	rs = 0;
	ref = g_op_tab[opid].args;
	while (i < MAX_ARGS_NUMBER && i < g_op_tab[opid].arg_cnt)
	{
		cr = (ocp >> (2 * (MAX_ARGS_NUMBER - (i + 1)))) & 3;
		ln += g_vlen[cr] / (1 + (g_ocpc[cr] == T_DIR && g_op_tab[opid].hdir));
		if ((!(g_ocpc[cr] & ref[i]) && (ref[i] || g_ocpc[cr]))
			|| (g_ocpc[cr] && i >= g_op_tab[opid].arg_cnt))
			rs |= 1;
		i++;
	}
	*off = (rs * ln);
	return (rs);
}
