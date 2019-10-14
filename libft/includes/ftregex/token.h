/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 09:59:58 by abaurens          #+#    #+#             */
/*   Updated: 2019/07/15 20:40:15 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "ftregex/t_token.h"

/*
**	tokenize.c
*/
char	tokenize(t_toklst *lst, const char *str, char end);

/*
**	token.c
*/
int		get_priority(char c);
char	is_operand(t_token *tok);
t_token	*get_token(const char *str);
char	is_quantifiable(t_token *tok);

/*
**	toklst.c
*/
void	clear_toklst(t_toklst *lst);
t_token	*new_token(char c, t_toktpe type);
t_token	*pop_tok(t_toklst *lst, t_token *tok);
t_token	*insert_after(t_toklst *const lst, t_token *tk, t_token *ps);
t_token	*insert_before(t_toklst *const lst, t_token *tk, t_token *ps);

/*
**	to_postfix.c
*/
void	to_postfix(t_toklst *lst);

#endif
