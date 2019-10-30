/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 02:52:22 by thberrid          #+#    #+#             */
/*   Updated: 2019/10/30 16:37:56 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"
#include "asm.h"

void	instruct_display(t_instruct *this)
{
	int		i;

	ft_printf("Label -> %s\n", this->label);
	ft_printf("ID -> %d\n", this->id);
	ft_printf("Instr. size -> %lu\n", this->len);
	ft_printf("Instr. index -> %u\n", this->byt_index);
	ft_printf("OCP -> ");
	ft_bprint_fd_rev(&(this->ocp), sizeof(this->ocp), 1);
	i = 0;
	ft_putchar('\n');
	while (this->params_str[i])
	{
		ft_printf("P%d -> %s\n", i + 1, this->params_str[i]);
		i += 1;
	}
}

void	instruct_display_all(t_instruct_head *head)
{
	size_t		i;
	t_instruct	*this;

	i = 0;
	this = head->head;
	ft_printf("Number of instructions ->  %lu\n", head->slen);
	ft_printf("Size of the program ->  %lu\n", head->length);
	ft_putendl("----------");
	while (i < head->slen)
	{
		instruct_display(this);
		this = this->next;
		ft_putendl("----------");
		i++;
	}
}
