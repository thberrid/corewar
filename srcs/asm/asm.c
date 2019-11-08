/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 05:19:53 by thberrid          #+#    #+#             */
/*   Updated: 2019/11/07 04:05:17 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <endianes.h>
#include "ftlib.h"
#include "ftio.h"
#include "asm.h"
#include "op.h"

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
	int			j;

	tmp = head->head;
	i = 0;
	while (i < head->slen)
	{
		j = 0;
		if (tmp->id)
			write(fd, &tmp->id, 1);
		if (g_op_tab[tmp->id].ocp)
			write(fd, &(tmp->ocp), 1);
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
	char	*name;
	char	*npos;
	int		fd;

	(void)head;

	if ((npos = ft_strrchr(av, '.')) > 0)
	{	
		if (!(name = ft_strnew(npos - av + 4)))
			return (-9);
		name = ft_strncpy(name, av, npos - av);
	}
	else
	{
		npos = av + ft_strlen(av);
		if(!(name = ft_strnew(ft_strlen(av) + 4)))
			return (-9);
	}
	//name = ft_strncpy(name, av, npos - av);
	ft_strlcat(name, ".cor", npos - av + 5);
	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	bin_to_system(&(header->magic), 4);
	bin_to_system(&(header->prog_size), 4);
	write(fd, header, sizeof(t_header));
	printinst(head, fd);
	close(fd);
	ft_printf("%s written\n", name);
	ft_strdel(&name);
	return (0);
}

int		set_labels(t_instruct_head *head)
{
	t_instruct	*tmp;
	t_instruct	*kev;
	int			val;
	size_t		i;
	int			k;
	size_t		v;

	tmp = head->head;
	i = 0;
	while (i < head->slen)
	{
		k = 0;
		while (k < 3 && tmp->params_str[k])
		{
			if (tmp->params_str[k][0] == LABEL_CHAR)
			{
				v = 0;
				kev = head->head;
				while (v < head->slen)
				{
					if (kev->label && ft_strcmp(kev->label, &(tmp->params_str[k][1])) == 0)
					{
						val = kev->byt_index - tmp->byt_index;
						ft_strdel(&(tmp->params_str[k]));
						tmp->params_str[k] = ft_itoa(val);
						break ;
					}
					v++;
					kev = kev->next;
				}
				if (v == head->slen)
				{
					head->line = tmp->line_n;
					if (head->cflag)
						tmp->params_str[k][0] = 0;	
					else
						return (-1);
				}
			}
			k++;
		}
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_instruct_head head;
	t_header		header;
	int				retrn_parse;
	int				retrn_labels;
	int				av_path;

	av_path = ac - 1;
	ft_bzero(&head, sizeof(t_instruct_head));
	if (ac == 1)
		return (ft_usage());
	if (av[1][0] == '-')
	{
		if (ft_contains('c', av[1]))
			head.cflag = 1;
		if (ac < 3)
			return (ft_printf("Error\n"));
	}
	ft_bzero(&header, sizeof(t_header));
	header.magic = COREWAR_EXEC_MAGIC;
	retrn_parse = ft_read(&head, av[av_path], &header);
	if (retrn_parse == 1)
	{
		if (!head.length)
			return (ft_errors(-6, 0));
		header.prog_size = head.length;
		retrn_labels = set_labels(&head);
		if (retrn_labels < 0)
			ft_errors(retrn_labels, head.line);
		if (retrn_labels && ac == 3 && ft_contains('a', av[1])) 
		{
			instruct_display_all(&head, &header);
			return(0);
		}
		if (retrn_labels > 0 && retrn_parse > 0)
			creat_file(&head, av[av_path], &header);
	}
	else
		ft_errors(retrn_parse, head.line);
	instruct_free(&head);
	return (0);
}
