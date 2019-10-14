/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:55:44 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/14 16:56:10 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

char				key_up(void);
char				key_end(void);
char				key_down(void);
char				key_left(void);
char				key_home(void);
char				key_right(void);

typedef char	(*t_key_func)(void);

static const struct	s_func_assignment
{
	char			*keycode;
	t_key_func		func;
}					g_tb[] __attribute__((unused)) = {
	{"[A", &key_up},
	{"[B", &key_down},
	{"[C", &key_right},
	{"[D", &key_left},
	{"OA", &key_up},
	{"OB", &key_down},
	{"OC", &key_right},
	{"OD", &key_left},
	{"OH", &key_home},
	{"OF", &key_end},
	{0x0, 0x0},
};

/*
**	the above is wrong because of the terminal i use in atom. gonna test each
**	keys of the keyboard and report them in this comment for both application
**	and classical mode
**
**	up		: \e[A \eOA
**	down	: \e[B \eOB
**	left	: \e[D \eOD
**	right	: \e[C \eOC
**	home	: \e[H \eOH
**	end		: \e[F \eOF
*/

typedef struct s_tree_	t_tree_;
struct				s_tree_
{
	const char		c;
	const char		*funcname;
	const int		nln;
	const t_tree_	*nxt[16];
};

/*
**	working but non ansi...
**
**	# define NODE(_c, _count, _childs) {_c, _count, _childs}
**	# define NODETAB(...) ((t_tree_[]){__VA_ARGS__})
**
**	t_tree_		g_test =
**		NODE('\033', 2, NODETAB(
**			NODE('[', 6, NODETAB(
**				NODE('A', 0, 0),
**				NODE('B', 0, 0),
**				NODE('C', 0, 0),
**				NODE('D', 0, 0),
**				NODE('E', 0, 0),
**				NODE('F', 0, 0)
**			)),
**			NODE('O', 6, NODETAB(
**				NODE('G', 0, 0),
**				NODE('H', 0, 0),
**				NODE('I', 0, 0),
**				NODE('J', 0, 0),
**				NODE('K', 0, 0),
**				NODE('L', 0, 0)
**			)),
**			NODE(0, 0, 0)
**		)
**	);
*/

/*
**	trying to find a workaround to get ansi compilant
*/
static const t_tree_	g_a = {'A', "key_up", 0, {0}};
static const t_tree_	g_b = {'B', "key_down", 0, {0}};
static const t_tree_	g_c = {'C', "key_right", 0, {0}};
static const t_tree_	g_d = {'D', "key_left", 0, {0}};
static const t_tree_	g_e = {'E', "key_bite", 0, {0}};
static const t_tree_	g_f = {'F', "key_end", 0, {0}};
static const t_tree_	g_g = {'G', "key_pute", 0, {0}};
static const t_tree_	g_h = {'H', "key_home", 0, {0}};

static const t_tree_	g_hook = {
	'[', 0, 6, {&g_a, &g_b, &g_c, &g_d, &g_e, &g_f, 0}
};

static const t_tree_	g_capo = {
	'O', 0, 6, {&g_a, &g_b, &g_c, &g_d, &g_e, &g_f, 0}
};

static const t_tree_	g_test = {
	'\033', 0, 2, {&g_hook, &g_capo, 0}
};

#endif
