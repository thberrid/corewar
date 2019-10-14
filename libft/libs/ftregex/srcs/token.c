/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:51:17 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/02 18:30:50 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftregex/t_token.h"
#include "ftlib.h"
#include "ftio.h"

int			get_priority(char c)
{
	if (c == '|')
		return (1);
	if (c == '+')
		return (2);
	if (c == '-')
		return (3);
	return (0);
}

char		is_quantifiable(t_token *tok)
{
	return (tok->type != QUANT && tok->type != SCOPE_OPN);
}

char		is_operand(t_token *tok)
{
	return (tok->type == CHAR || tok->type == SPEC || tok->type == SHORT);
}

t_token		*get_token(char const *str)
{
	t_token	*tok;

	if (!(tok = ft_memalloc(sizeof(t_token))))
		return (NULL);
	tok->len = 1;
	tok->c = *str;
	tok->type = UNKNOWN;
	return (tok);
}
