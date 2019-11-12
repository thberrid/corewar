/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:42:25 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/12 19:26:14 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H

# include "process.h"
# include "vm.h"

# define DUMP_LEN	32

# define UOP		"    %-5s%-5s: %s\n"
# define UVB		"%19s : %s\n"

# ifdef ZAZ
#  define USGAFF	" (Default is to hide it)"
#  define SPLAYER	"Player "
#  define LIVEBRAC	" ("
#  define SALIVE	") is said to be alive\n"
#  define WINMSG	"Contestant %d, \"%s\", has won !\n"
# else
#  define USGAFF	""
#  define SPLAYER	"un processus dit que le joueur "
#  define LIVEBRAC	"("
#  define SALIVE	") est en vie\n"
#  define WINMSG	"le joueur %d(%s) a gagne\n"
# endif

void	out_ctd(t_scycle ctd);
void	out_cycles(t_cycle cycle);
void	out_pc(t_proc *proc, const t_ind off);

#endif
