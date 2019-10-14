/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bint_mul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:12:29 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/09 21:43:02 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio/dragon.h"
#include "ftlib.h"

void		bimul(t_bint *res, t_bint *n1, t_bint *n2)
{
	int		i;
	t_bint	r;
	t_proc	t;
	t_proc	c;

	if ((i = -1) && n1->len < n2->len)
		swap((uintptr_t *)&n1, (uintptr_t *)&n2);
	ft_bzero(r.blks, sizeof(t_block) * (n1->len + n2->len));
	while ((size_t)(++i) < n2->len)
	{
		if (!n2->blks[i] || (r.len = 0))
			continue ;
		c = 0;
		while (r.len < n1->len)
		{
			t = (t_proc)n2->blks[i] * (t_proc)n1->blks[r.len] + c;
			t += r.blks[i + r.len];
			c = (t >> BIT_PER_BLOCK);
			r.blks[i + r.len] = (t & MAX_BINT_VALS);
			r.len++;
		}
		r.blks[i + r.len] = c & MAX_BINT_VALS;
	}
	r.len = n1->len + n2->len - (!r.blks[n1->len + n2->len - 1]);
	*res = r;
}

void		bimul2(t_bint *res, t_bint *n)
{
	t_bint	r;
	t_proc	t;
	t_proc	c;

	c = 0;
	r.len = 0;
	r.blks[0] = 0;
	while (r.len < n->len)
	{
		t = n->blks[r.len];
		r.blks[r.len++] = (t << 1) | c;
		c = (t >> 31);
	}
	if (c && (r.blks[r.len] = (c & MAX_BINT_VALS)))
		r.len++;
	*res = r;
}

void		bimul10(t_bint *res, t_bint *n)
{
	t_bint	r;
	t_proc	t;
	t_proc	c;

	c = 0;
	r.len = 0;
	r.blks[0] = 0;
	while (r.len < n->len)
	{
		t = c + ((t_proc)n->blks[r.len] * 10);
		r.blks[r.len++] = (t & MAX_BINT_VALS);
		c = (t >> BIT_PER_BLOCK);
	}
	if (c && (r.blks[r.len] = (c & MAX_BINT_VALS)))
		r.len++;
	*res = r;
}

void		bimulint(t_bint *res, t_bint *n, unsigned int v)
{
	t_bint	r;
	t_proc	t;
	t_proc	c;

	c = 0;
	r.len = 0;
	r.blks[0] = 0;
	while (r.len < n->len)
	{
		t = c + ((t_proc)n->blks[r.len] * v);
		c = (t >> BIT_PER_BLOCK);
		r.blks[r.len++] = (t & MAX_BINT_VALS);
	}
	if ((r.blks[r.len] = (c & MAX_BINT_VALS)))
		r.len++;
	*res = r;
}
