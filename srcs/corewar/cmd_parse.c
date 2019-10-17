/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:32:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/17 08:22:32 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"
#include "ftlib.h"
#include "vm.h"

/*
**	./corewar [-dump nb_cycles] [[-n num] champ1.cor] ...
**	-dump suivi d'un nombre, n'importe ou dans la commande excepte
**	entre un -n et son num ou entre un -n et son champion.
**	-n suivi d'un nombre puis d'un champion, partout excepte entre -dump et
**	son nombre
**
**	les nombres sont des unsigned int de 32 bit de long (uint32_t)
*/

static void	*parse_dump(char **av)
{
	char	e;

	e = 0;
	if (!e && (!av || !*av))
		e = ft_print_error("missing argument for '"DUMP_FLG"' flag...\n");
	if (e)
		return (NULL);
	ft_printf("dump value: %s\n", *av);
	return (av);
}

static void	*parse_num(char **av)
{
	ft_printf("forcing value '%s' for champ ", *av++);
	ft_printf("\"%s\"\n", *av);
	return (av);
}

static void	*(*const g_f[2])(char **av) = {
	&parse_dump,
	&parse_num
};

void	parse_args(int ac __attribute__((unused)), char **av)
{
	int			j;
	const char	*t[2] = {
		DUMP_FLG,
		NUM_FLG
	};

	while (av && *++av)
	{
		j = 0;
		while (j < 2 && !ft_strequ(t[j], *av))
			++j;
		if (j < 2)
			av = g_f[j](++av);
		else
			ft_printf("champ path: \"%s\"\n", *av);
	}
}
