/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 05:19:53 by thberrid          #+#    #+#             */
/*   Updated: 2019/10/19 23:15:55 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int		main(int ac, char **av)
{
	t_instruct_head head;
	t_header		header;
	size_t			i = 0;
	t_instruct		*tmp;

	if (ac != 2)
		ft_printf("Error\n");
	ft_bzero(&header, sizeof(t_header));
	ft_bzero(&head, sizeof(t_instruct_head));
	ft_printf("ret: %d\n", ft_read(&head,av[1], &header));
	tmp = head.head;
	while (i < head.slen)
	{
		ft_printf("Label : %s\n", tmp->label);
		ft_printf("ID : %d\n", tmp->id);
		i++;
		tmp = tmp->next;
	}
	clean_struct(&head);
	return (0);
}
