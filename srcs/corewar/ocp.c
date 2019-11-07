/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:54:53 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/07 10:32:55 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_DISABLE_WARNINGS

#include "config.h"
#include "arena.h"
#include "op.h"
#include "ftio.h"

static const t_ind	g_arg_sizes[4] = {
	0, 1, IND_SIZE, REG_SIZE
};

static const t_byte	g_ocpc[4] = {
	0, T_REG, T_DIR, T_IND
};

t_ind	get_arg_size(t_byte ocp, uint32_t opid)
{
	if (ocp == DIR_CODE && g_op_tab[opid].hdir)
		--ocp;
	return (g_arg_sizes[ocp]);
}

t_ind	check_ocp(t_byte ocp, uint32_t opid)
{
	int				i;
	t_ind			ln;
	t_byte			cr;
	t_byte			rs;
	const t_byte	*ref;

	ln = 0;
	rs = 0;
	i = MAX_ARGS_NUMBER - 1;
	ref = g_op_tab[opid].args;
	while (i-- > 0)
	{
		cr = (ocp >>= 2) & 3;
		ln += (g_arg_sizes[cr] - (g_ocpc[cr] == T_DIR && g_op_tab[opid].hdir));
		if ((!(g_ocpc[cr] & ref[i]) && (ref[i] || g_ocpc[cr]))
			|| (g_ocpc[cr] && i >= g_op_tab[opid].arg_cnt))
			rs |= 1;
	}
	return (rs * ln);
}
