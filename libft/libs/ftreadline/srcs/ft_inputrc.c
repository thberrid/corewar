/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputrc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:25:04 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/14 16:57:01 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_DISABLE_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "ftreadline/keys.h"
#include "ftreadline/ft_inputrc.h"
#include "ftio.h"

/*
**	static char	tree_add(t_tree *node, register const char *nodes, t_fkey func)
**	{
**		register size_t	i;
**		t_tree			*new;
**
**		i = 0;
**		new = NULL;
**		if (!*nodes)
**		{
**			node->f = func;
**			return (0);
**		}
**		while (!new && i < node->ncnt)
**			if (node->nexts[i++]->c == *nodes)
**				new = node->nexts[i - 1];
**		ft_printf("  adding '%c' after '%#R'\n", *nodes, node->c);
**		if (!new)
**		{
**			ft_printf("    '%c' doesn't exist yet. allocating memory...\n",
**				*nodes);
**			if (!(new = malloc(sizeof(t_tree))))
**				return (-1);
**			new->f = 0x0;
**			new->ncnt = 0;
**			new->c = *nodes;
**			node->nexts[node->ncnt++] = new;
**		}
**		return (tree_add(new, nodes + 1, func));
**	}
**
**	static char	build_input_tree(t_tree *root)
**	{
**		int		i;
**
**		i = 0;
**		while (g_tb[i].keycode)
**		{
**			ft_printf("adding '%s'\n", g_tb[i].keycode);
**			if (tree_add(root, g_tb[i].keycode, g_tb[i].func))
**				return (1);
**			++i;
**		}
**		return (0);
**	}
*/

void	print_tree(const t_tree_ *cur, int j)
{
	int		i;

	i = 0;
	ft_printf("%*s'%R': ", j, "", cur->c);
	if (cur->nln)
		ft_printf("[%d](", cur->nln);
	else
		ft_printf("%s()\n", cur->funcname);
	while (cur->nxt[i])
	{
		ft_printf("'%c'%s", cur->nxt[i]->c, cur->nxt[i + 1] ? ", " : ")\n");
		++i;
	}
	i = 0;
	while (cur->nxt[i])
		print_tree(cur->nxt[i++], j + 2);
}

/*
**t = &g_test;
**ft_printf("'%R'(%d) : ('%c', '%c')\n", t->c, t->nln,
**			t->nxt[0]->c, t->nxt[1]->c);
**t = t->nxt[0];
**ft_printf("'%R' : [%d]('%c', '%c', '%c', '%c', '%c', '%c')\n", t->c, t->nln,
**			t->nxt[0]->c, t->nxt[1]->c, t->nxt[2]->c,
**			t->nxt[3]->c, t->nxt[4]->c, t->nxt[5]->c);
**t = g_test.nxt[1];
**ft_printf("'%R' : [%d]('%c', '%c', '%c', '%c', '%c', '%c')\n", t->c, t->nln,
**			t->nxt[0]->c, t->nxt[1]->c, t->nxt[2]->c,
**			t->nxt[3]->c, t->nxt[4]->c, t->nxt[5]->c);
*/

t_tree	*get_input_tree(void)
{
	print_tree(&g_test, 0);
	return (0x0);
}
