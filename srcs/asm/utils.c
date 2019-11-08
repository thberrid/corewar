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

int		ft_errors(int err, int line_n)
{
	err *= -1;
	static char	*str[] = {
		"Can't read source file",
		"Lexical error at ligne :",
		"Syntax error at line :",
		"Invalid parameter at line :",
		"Program too big",
		"Invalid instruction at line :",
		"No instruction found :(",
		"name too long T-T at line :",
		"comment too long T-T at line :",
		"malloc Error"
	};
	ft_putstr_fd(str[err], 2);
	ft_putchar_fd(' ', 2);
	if(line_n)
		ft_putnbr_fd(line_n, 2);
	ft_putendl_fd("", 2);
	return (0);
}

int		ft_usage(void)
{
	ft_printf("Usage: ./asm [-a] <sourcefile.s>\n");
	ft_printf("	-a : Instead of creating a .cor file, outputs a stripped");
	ft_printf("and annotated version of the code to the standard output\n");
	return(0);
}