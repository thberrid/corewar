/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 07:13:20 by smoreno-          #+#    #+#             */
/*   Updated: 2019/11/03 07:15:32 by smoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_errors(int err, int line_n)
{
	err *= -1;
	static char	*str[] = {
		"Can't read source file",
		"Lexical error at ligne",
		"Syntax error",
		"Invalid parameter",
		"Program too big",
		"Invalid instruction"
	};
	ft_putstr_fd(str[err], 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(line_n, 2);
	ft_putendl_fd("", 2);
	
}