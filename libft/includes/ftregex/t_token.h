/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 09:49:21 by abaurens          #+#    #+#             */
/*   Updated: 2019/07/15 20:53:14 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TOKEN_H
# define T_TOKEN_H

# include <string.h>

typedef struct s_token	t_token;

typedef enum	e_toktpe
{
	OP,
	CHAR,
	SPEC,
	QUANT,
	SHORT,
	SCOPE_OPN,
	SCOPE_CLS,
	UNKNOWN
}				t_toktpe;

struct			s_token
{
	t_token		*next;
	t_token		*prev;
	t_toktpe	type;
	char		c;
	size_t		len;
};

typedef struct	s_toklst
{
	t_token		*head;
	t_token		*tail;
	size_t		size;
}				t_toklst;

#endif
