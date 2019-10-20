/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:49:49 by baurens           #+#    #+#             */
/*   Updated: 2019/10/21 01:08:38 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "endianes.h"
#include "arena.h"
#include "ftlib.h"
#include "op.h"
#include "vm.h"

/*
**	une phrase basique en français
**	français en basique phrase une
*/

t_champ	load_file(t_vm *vm, t_champ *chmp)
{
	int			fd;
	ssize_t		rd;
	t_header	head;

	chmp->pc = (MEM_SIZE / vm->psize * chmp->id);
	if ((fd = open(chmp->path, O_RDONLY)) < 0)
		exit(ft_print_error("Can't open '%s': %m.\n", chmp->path));
	if ((rd = read(fd, &head, sizeof(head))) < 0 && (close(fd) | 1))
		exit(ft_print_error("can't read '%s': %m.\n", chmp->path));
	if ((size_t)rd < sizeof(head) && (close(fd) | 1))
		exit(ft_print_error("'%s': Invalid or corrupted file.\n", chmp->path));
	bin_to_system(&head.magic, sizeof(head.magic));
	bin_to_system(&head.prog_size, sizeof(head.prog_size));
	if (head.magic != COREWAR_EXEC_MAGIC && (close(fd) | 1))
		exit(ft_print_error("'%s': Invalid or corrupted file.\n", chmp->path));
	if (head.prog_size > CHAMP_MAX_SIZE && (close(fd) | 1))
		exit(ft_print_error("'%s': File too big.\n", chmp->path));
	if ((rd = read(fd, g_map + chmp->pc, head.prog_size)) < 0)
		exit(ft_print_error("can't read '%s': %m.\n", chmp->path));
	if (close(fd) < 0)
		exit(ft_print_error("can't close '%s': %m.\n", chmp->path));
	if (rd < head.prog_size)
		exit(ft_print_error("'%s': Invalid or corrupted file.\n", chmp->path));
	return (*chmp);
}
