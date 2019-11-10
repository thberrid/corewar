/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 07:13:20 by smoreno-          #+#    #+#             */
/*   Updated: 2019/11/08 09:11:48 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_errors(int err, int line_n)
{
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

	err *= -1;
	ft_putstr_fd(str[err], 2);
	ft_putchar_fd(' ', 2);
	if (line_n)
		ft_putnbr_fd(line_n, 2);
	ft_putendl_fd("", 2);
	return (0);
}

int		ft_usage(void)
{
	ft_printf("Usage: ./asm [-a] <sourcefile.s>\n");
	ft_printf("	-a : Instead of creating a .cor file, outputs a stripped");
	ft_printf("and annotated version of the code to the standard output\n");
	return (0);
}

int		strtobin(int fd, char *param, uint32_t size)
{
	int		tmp;

	if (param[0] == LABEL_CHAR)
	{
		write(fd, "##", size);
		return (0);
	}
	tmp = ft_atoi(param);
	bin_to_system(&tmp, size);
	write(fd, &tmp, size);
	return (0);
}

int		printinst(t_instruct_head *head, int fd)
{
	t_instruct	*tmp;
	size_t		i;
	int			j;

	tmp = head->head;
	i = 0;
	while (i < head->slen)
	{
		j = 0;
		if (tmp->id)
			write(fd, &tmp->id, 1);
		if (g_op_tab[tmp->id].ocp)
			write(fd, &(tmp->ocp), 1);
		while (j < g_op_tab[tmp->id].arg_cnt)
		{
			strtobin(fd, tmp->params_str[j], tmp->params_bits[j]);
			j++;
		}
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	set_rethd(int fl, int *rethd)
{
	if (fl == 1)
	{
		*rethd |= IS_NAME;
		*rethd |= NAME_DONE;
		*rethd &= ~IS_COMMENT;
	}
	else
	{
		*rethd |= IS_COMMENT;
		*rethd |= COMMENT_DONE;
		*rethd &= ~IS_NAME;
	}
}
