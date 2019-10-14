/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputrc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:04:42 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/02 17:05:44 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INPUTRC_H
# define FT_INPUTRC_H

# include <string.h>

# define MAX_BRANCH	16

typedef char	(*t_fkey)(void);

typedef struct s_tree	t_tree;

struct			s_tree
{
	char		c;
	size_t		ncnt;
	t_tree		*nexts[MAX_BRANCH];
	t_fkey		f;
};

t_tree			*get_input_tree(void);

#endif
