/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:32:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/15 11:19:36 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"
#include "ftlib.h"

/*
**	./corewar [-dump nb_cycles] [[-n num] champ1.cor] ...
**	-dump suivi d'un nombre, n'importe ou dans la commande excepte
**	entre un -n et son num ou entre un -n et son champion.
**	-n suivi d'un nombre puis d'un champion, partout excepte entre -dump et
**	son nombre
**
**	les nombres sont des unsigned int de 32 bit de long (uint32_t)
*/

void	parse_dump(char ***avp)
{

}

void	parse_dump(char ***avp)
{

}

void	parse_args(int ac, char **av)
{
	int	i;

	i = 0;
	while (--ac)
	{
		ft_printf("av[%d] = \"%s\"\n", i++, *++av);
	}
}
