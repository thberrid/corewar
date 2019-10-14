/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftregex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:57:17 by abaurens          #+#    #+#             */
/*   Updated: 2019/07/15 21:11:08 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTREGEX_H
# define FTREGEX_H

# define RE_SCP_OPN	"(["
# define RE_SCP_CLS	")]"
# define RE_QUANT	"*+?{}"
# define RE_SPC		".^$"
# define RE_SHORT	"sSdDwW"
# define RE_ESC_RL	"\n\t\r"
# define RE_ESC		"ntr0"

# define RE_C_RNG	'-'
# define RE_C_NOT	'^'
# define RE_C_AND	'+'
# define RE_C_OR	'|'
# define RE_C_ESC	'\\'
# define RE_C_SEP	','

/*
**	\s = whitespaces		[\r\n\t\f\v ]
**	\S = non-whitespaces	[^\r\n\t\f\v ]
**	\d = digit char			[0-9]
**	\D = non-digit char		[^0-9]
**	\w = word char			[a-zA-Z0-9_]
**	\W = non-word char		[^a-zA-Z0-9_]
**
**	\n = new line '\n'
**	\t = tab '\t'
**	\r = cariage return '\r'
**	\0 = null char '\0'
*/

/*
**	regex.c
*/
void	*ft_regex(const char *str);

#endif
