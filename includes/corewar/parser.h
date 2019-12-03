/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:31:18 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/05 16:41:33 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "vm.h"

typedef struct	s_dispatch
{
	const char	*opt;
	char		**(*callback)(t_vm *vm, char **av);
}				t_dispatch;

char			**parse_aff(t_vm *vm, char **av);
char			**parse_num(t_vm *vm, char **av);
char			**parse_file(t_vm *vm, char **av);
char			**parse_dump(t_vm *vm, char **av);
char			**parse_zaz_dump(t_vm *vm, char **av);
char			**parse_verbosity(t_vm *vm, char **av);

static const t_dispatch	g_parser[] = {
	{"-a", parse_aff},
	{"-n", parse_num},
	{"-d", parse_zaz_dump},
	{"-dump", parse_dump},
	{"-v", parse_verbosity},
	{0, parse_file},
};

#endif
