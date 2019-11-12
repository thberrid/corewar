/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 02:52:22 by thberrid          #+#    #+#             */
/*   Updated: 2019/11/08 06:20:17 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	instruct_display(t_instruct *this)
{
	int		i;

	if (this->label)
		ft_printf("Label -> %s\n", this->label);
	else
		ft_printf("\n");
	ft_printf("ID -> %d\n", this->id);
	bin_to_system(&(this->ocp), 1);
	ft_printf("OCP -> %u\n", (unsigned char)this->ocp);
	i = 0;
	while (i < 3)
	{
		ft_printf("P%d -> %s\n", i + 1, this->params_str[i]);
		i += 1;
	}
}

void	instruct_display_all(t_instruct_head *head, t_header *header)
{
	size_t		i;
	t_instruct	*this;

	i = 0;
	this = head->head;
	ft_printf("Number of instructions ->  %lu\n", head->slen);
	ft_printf("Size of the program ->  %lu bytes\n", head->length);
	ft_printf("Name : \"%s\"\n", header->prog_name);
	ft_printf("Comment : \"%s\"\n\n", header->comment);
	ft_putendl("----------");
	while (i < head->slen)
	{
		ft_printf("%u	(%lu)	: ", this->byt_index, this->len);
		instruct_display(this);
		this = this->next;
		ft_putendl("----------");
		i++;
	}
}
