/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 07:24:09 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/15 08:31:58 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"
//#include "../../libft/includes/ftlib.h"
//s#include "../../libft/includes/ftio.h"
//#include "ftlib.h"

int		main(int ac, char **av)
{
	t_instruct_head head;
	t_header		header;
	size_t			i = 0;
	t_instruct		*tmp;

	if (ac != 2)
		ft_printf("Error\n");
	ft_printf("ret: %d\n", ft_read(&head,av[1], &header));
	tmp = head.head;
	while (i < head.slen)
	{
		ft_printf("Label : %s\n", tmp->label);
		ft_printf("ID : %d\n", tmp->id);
		i++;
		tmp = tmp->next;
	}
//	get_next_line(1,av);

//	ft_printf("header = %s\n", header.comment);
//	ft_printf("name = %s\n", header.prog_name);
	return (0);
}
