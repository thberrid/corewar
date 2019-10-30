/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 05:19:53 by thberrid          #+#    #+#             */
/*   Updated: 2019/10/30 16:38:52 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"
#include "ftio.h"
#include "asm.h"

int		main(int ac, char **av)
{
	t_instruct_head head;
	t_header		header;
	int				retrn;

	(void)retrn;
	if (ac != 2)
		ft_printf("Error\n");
	ft_bzero(&header, sizeof(t_header));
	ft_bzero(&head, sizeof(t_instruct_head));
	retrn = ft_read(&head,av[1], &header);
//	ft_printf("ret: %d\n", retrn);
	instruct_display_all(&head);
	instruct_free(&head);
	return (0);
}
