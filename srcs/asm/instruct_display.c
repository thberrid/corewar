/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 02:52:22 by thberrid          #+#    #+#             */
/*   Updated: 2019/10/21 06:55:18 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	instruct_display(t_instruct *this)
{
	int		i;

	ft_printf("Label -> %s\n", this->label);
	ft_printf("ID -> %d\n", this->id);
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
	ft_printf("LEN : %lu\n", head->slen);
	while (i < head->slen)
	{
		instruct_display(this);
		this = this->next;
		ft_putendl("----------");
		i++;
	}
}
