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

	if (this->label)
		ft_printf("Label -> %s\n", this->label);
	else
		ft_printf("\n");
	ft_printf("ID -> %d\n", this->id);
	//ft_printf("Instr. size -> %lu\n", this->len);
//	ft_printf("Instr. index -> %u\n", this->byt_index);
	ft_printf("OCP -> ");
	ft_bprint_fd_rev(&(this->ocp), sizeof(this->ocp), 1);
	i = 0;
	ft_putchar('\n');
	while (i < 3)
	{
		ft_printf("P%d -> %s\n", i + 1, this->params_str[i]);
		i += 1;
	}
}

void	instruct_display_all(t_instruct_head *head, t_header *header)
{
	size_t		i;
	size_t		len;
	t_instruct	*this;

	i = 0;
	len = 0;
	this = head->head;
	ft_printf("Number of instructions ->  %lu\n", head->slen);
	ft_printf("Size of the program ->  %lu bytes\n", head->length);
	ft_printf("Name : \"%s\"\n", header->prog_name);
	ft_printf("Comment : \"%s\"\n\n", header->comment);	
	ft_putendl("----------");
	while (i < head->slen)
	{
		ft_printf("%lu	(%lu)	: ", len, this->len);
		len += this->len;
		instruct_display(this);
		this = this->next;
		ft_putendl("----------");
		i++;
	}
}
