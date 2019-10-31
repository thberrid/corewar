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
#include <fcntl.h>
#include <unistd.h>
#include <endianes.h>

int		strtobin(int fd, char *param, t_instruct_head *head, uint32_t size)
{
		int		tmp;
		(void)head;
	//if (!(inst->params_str[i] = ft_memalloc(inst->params_bits[i])))
		//	return (0);
		if (param[0] == LABEL_CHAR)
		{
			write(fd, "##", size);
			return (0);
		}
		tmp = ft_atoi(param);
		bin_to_system(&tmp, size);
		write(fd, &tmp, size);
		return (0);
}

int		printinst(t_instruct_head *head, int fd)
{
	t_instruct	*tmp;
	size_t		i;
	int		j;

	tmp = head->head;
	i = 0;
	while (i < head->slen)
	{
		j = 0;
		write(fd,&tmp->id,1);
		if (g_op_tab[tmp->id].ocp)
			write(fd,&(tmp->ocp),1);
		while (j < g_op_tab[tmp->id].arg_cnt)
		{
			strtobin(fd, tmp->params_str[j], head, tmp->params_bits[j]);	
			j++;
		}
		tmp = tmp->next;
		i++;
	}
	return (0);
}
int		creat_file(t_instruct_head *head, char *av, t_header *header)
{
	(void)head;
	char	*name;
	char	*npos;
	int		fd;

	npos = ft_strrchr(av, '.');
	name = ft_strnew(npos - av + 4);
	name = ft_strncpy(name, av, npos - av);
	ft_strlcat(name, ".cor", npos - av + 5);
	fd = open(name,O_CREAT|O_WRONLY|O_TRUNC,0600);
	bin_to_system(&(header->magic), 4);
	bin_to_system(&(header->prog_size), 4);
	write(fd, header, sizeof(t_header));
	printinst(head, fd);
	close(fd);
	return(0);
}

int		set_labels(t_instruct_head *head)
{
	t_instruct	*tmp;
	t_instruct	*kev;
	int 		i;
	int			k;
	int			v;

	tmp = head->head;
	i = 0;
	while (i < head->slen)
	{
		k = 0;
		while (k < 3)
		{
			if (tmp->params_str[k][0] == LABEL_CHAR)
			{
				v = 0;
				kev = head->head;
				while ()
			}
			
		}
		tmp = tmp->next;
		i++;
	}
}

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
	header.magic = COREWAR_EXEC_MAGIC;
	retrn = ft_read(&head,av[1], &header);
	ft_printf("ret: %d\n", retrn);
	header.prog_size = head.length;
	instruct_display_all(&head);
	retrn = set_labels(&head);
	ft_printf("ret: %d\n", retrn);
	creat_file(&head, av[1], &header);
//	instruct_free(&head);
	return (0);
}
