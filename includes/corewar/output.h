/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:42:25 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/03 03:27:26 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H

# include "process.h"
# include "vm.h"

# define DUMP_LEN	32

# define UOP		"    %-5s%-5s: %s\n"
# define UVB		"%19s : %s\n"
# define VM_HEXA	"0123456789abcdef"

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
void	out_pc(t_proc *proc, register t_ind off);

char	*ft_nbrcat(char *dst, register int n);
char	*ft_lnbrcat(char *dst, register long int n);
char	*ft_unbrcat(char *dst, register unsigned int n);
char	*ft_lunbrcat(char *dst, register unsigned long int n);

void	flush_buffer(int fd);
void	corewar_putchar(const int fd, char c);
void	corewar_putstr(const int fd, const char *buff);
void	corewar_write(const int fd, const char *buff, int size);

void	corewar_putnbr(const int fd, register int n);
void	corewar_putlnbr(const int fd, register long int n);
void	corewar_putunbr(const int fd, register unsigned int n);
void	corewar_putlunbr(const int fd, register unsigned long int n);

#endif
