/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instru.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <smoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:52:32 by smoreno-          #+#    #+#             */
/*   Updated: 2019/10/30 16:39:05 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"
#include "ftio.h"
#include "asm.h"

/*
** make a copy of a label: into a t_instruct
*/

int		ft_getlab(char **line, t_instruct *inst)
{
	int i;

	i = 0;
	while ((*line)[i] && (*line)[i] != LABEL_CHAR && !(ft_isspace((*line)[i])))
	{
		if (!ft_contains((*line)[i], LABEL_CHARS))
			return (-1);
		i++;
	}
	if ((*line)[i] == LABEL_CHAR)
	{
		if (!(inst->label = ft_strnew(i)))
			return (-1);
		inst->label = ft_strncpy(inst->label, *line, i);
		*line += i + 1;
	}
	return (0);
}

/*
** take the name of an instruction and
** return the op_code
*/

int		ft_getopcode(char **line, t_instruct *inst)
{
	int		i;
	int		j;

	i = 0;
	while (ft_isspace(**line))
		(*line)++;
	while ((*line)[i] && (*line)[i] != DIRECT_CHAR && !(ft_isspace((*line)[i])))
		i++;
	if (!i)
		return (-1);
	j = 0;
	while (g_op_tab[j].name)
	{
		if (!ft_strncmp(g_op_tab[j].name, *line, i))
		{
			inst->id = g_op_tab[j].id;
			*line += i;
			return (1);
		}
		j++;
	}
	return (-1);
}

/*
** take the opcode,
** return the nmbr of argument
*/

int		get_paramlen(int opcode)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (opcode == g_op_tab[i].id)
			return (g_op_tab[i].arg_cnt);
		i++;
	}
	return (-1);
}

/*
** ok lol kevin has got a problem with the leaks and valgrind and stuff
*/

void	free_split(char **params)
{
	int		i;

	i = 0;
	while (params[i])
	{
		free(params[i]);
		i += 1;
	}
	free(params);
}

/*
** return le nombre d'occurence d'un char dans une *str
** est utilisé pour compter le nombre de ',' qui separent les parametres
*/

int		ft_strcountchar(char *str, char c)
{
	int		sum;

	sum = 0;
	while (*str)
	{
		if (*str == c)
			sum += 1;
		str += 1;
	}
	return (sum);
}

/*
** take an ocp (REG_CODE / DIR_CODE / IND_CODE)
** and look in g_op_tab.args
** en utilisant les bitwise operator
** par exemple : par exemple pour `ld` on a {T_DIR | T_IND, T_REG}
** ce qui donne {2 | 4, 1}, en binaire {0010 | 0100, 0001}
** et du coup le | il superpose tout c'est trop pratique et COMME PAR HASARD OUPS aucun bit ne se superpose
** ça donne {0110 | 0001} et du coup on peut regarder facilement
*/

int		is_paramtype_allowed(char param_type, t_instruct *inst, int i)
{
	if (param_type == IND_CODE)
		param_type = T_IND;
	if ((g_op_tab[inst->id].args[i] ^ param_type) < g_op_tab[inst->id].args[i])
		return (1);
	return (0);
}

int		get_octet(t_byte id, char param_type)
{
	if (param_type == REG_CODE)
		return (1);
	if (param_type == IND_CODE)
		return (2);
	if (param_type == DIR_CODE && g_op_tab[id].hdir)
		return (2);
	return (4);	
}

/*
** ici on regarde le premier char pour savoir si rX ou si % ou si rien
*/

int		ft_checkchar(char *str, char *type)
{
	int		j;

	j = 0;
	while (str[j])
	{
		if (ft_contains(str[j], type) != 1 &&  !ft_isspace(str[j]))
			return (0);	
		j++;
	}
	return (1);
}

t_arg_type	get_ocp(char **param_raw, int param_len, t_instruct *inst)
{
	t_arg_type	ocp;
	int			i;
	int			j;
	int			ret;
	char		param_type;

	i = 0;
	ocp = 0;
	(void)param_len;
	ret = 1;
	while (param_raw[i])
	{
		j = 0;
		while (ft_isspace(param_raw[i][j]))
			j++;
		if (param_raw[i][j] == 'r' && (ret = param_raw[i][j + 1])
			&& (ret = ft_checkchar(&param_raw[i][j + 1], REG_CHAR)))
			param_type = REG_CODE;
		else if (ret == 0)
			return (0);
		else if (param_raw[i][j] == '%')
			param_type = DIR_CODE;
		else
			param_type = IND_CODE;
		if (!is_paramtype_allowed(param_type, inst, i))
			return (0);
		ocp += ((param_type << (3 - i) * 2));
		inst->params_bits[i] = get_octet(inst->id, param_type);
		/*
		if (!(inst->params_str[i] = ft_memalloc(inst->params_bits[i])))
			return (0);
		j = ft_atoi(&param_raw[i][j]);
		printf("%d\n", j);
		ft_memcpy(&inst->params_str[i], &j, inst->params_bits[i]);
		bin_to_system(&inst->params_str[i], inst->params_bits[i]);
		*/
		i++;
	}
	return (ocp);
}

int		param_to_inst(char **param_raw, t_instruct *inst, char **line)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (param_raw[i])
	{
		j = 0; 
		while (ft_isspace(param_raw[i][j]))
			j++;
		if (param_raw[i][j] == DIRECT_CHAR || param_raw[i][j] == 'r')
			j++;
		len = 0;
		while (param_raw[i][j + len] && !ft_isspace(param_raw[i][j + len]))
			len += 1;
		if (!(inst->params_str[i] = ft_strnew(len)))
			return (0);
		ft_bzero(inst->params_str[i], len);
		ft_strncpy(inst->params_str[i], &(param_raw[i][j]), len);
		(*line) += (j + 1);
		i += 1;
	}
	return (1);
}

/*
** 1 check if the number of arguments is correct
** 2 then do str split (str ',')
** 3 encode the ocp (and verify if each parameter has an allowed type)
** 4 save it into the t_instruct
** 5 make money
*/

int		ft_getparams(char **line, t_instruct *inst)
{
	char	**param_raw;
	int		param_len;

	param_len = get_paramlen(inst->id);
	if (param_len != 1 + ft_strcountchar(*line, SEPARATOR_CHAR))
		return (-1);
	if (!(param_raw = ft_strsplit(*line, SEPARATOR_CHAR)))
		return (-1);
	if (!(inst->ocp = get_ocp(param_raw, param_len, inst)))
		return (-1);
	if (!param_to_inst(param_raw, inst, line))
		return (-1);
	free_split(param_raw);
	return (1);
}

/*
** ok go ask to the double-link-listed girl if you want really want to know
*/

t_instruct	*add_inst(t_instruct_head *head)
{
	t_instruct	*new;

	if (!(new = ft_memalloc(sizeof(t_instruct))))
		return (NULL);
	new->next = head->head ? head->head : new;
	new->prev = head->head ? head->head->prev : new;
	if (head->slen == 0)
		head->head= new;
	new->prev->next = new;
	new->next->prev = new;
	head->slen++;
	return (new);
}

/*
** ok the idea is
** le op code is 1 octet
** + 1 octet for the ocp, but he is optionnal so you have to check
** + 1, 2 or 4 for each argument soooooo you have to check each one
** with bitwise again
** et voila
*/

int		update_progsize(t_instruct_head *head, t_instruct *inst)
{
	int		prog_size;
	int		i;
	char	code;

	prog_size = 1;
	if (g_op_tab[inst->id].ocp)
		prog_size += 1;
	i = 0;
	while (i < 3)
	{
		code = 0;
		code += (inst->ocp >> 2 * (3 - i)) & 2;
		code += (inst->ocp >> (2 * (3 - i))) & 1;
		if (code == 1)
			prog_size += 1;
		else if (code == 3)
			prog_size += 2;
		else if (code != 0)
			prog_size += (g_op_tab[inst->id].hdir ? 2 : 4);
		i++;
	}
	inst->len = prog_size;
	inst->byt_index = head->length;
	head->length += prog_size;
	//ft_printf("LAAA : %zu\n", inst->id, );
	if (head->length > 2000)
	{
		ft_printf("LAAA : %zu\n", head->length);
		return (-1);
	}
	return (0);
}

/*
** just to see if there is no #blablabla at the end of the line
** but that remind me that maybe if there is a #blabal,blab, it coulb be a problem
*/

void		check_endline(char *line)
{
	while (line && *line)
	{
		if (*line == COMMENT_CHAR)
			ft_bzero(line, ft_strlen(line));
		line++;
	}
}

int		check_instruct(char *line, t_instruct_head *head)
{
	int		i;
	t_instruct	*inst;

	i = 0;
	(void)i;
	check_endline(line);
	if (!(inst = add_inst(head)))
		return (-1);
	while (ft_isspace(*line))
		line++;
	if (ft_getlab(&line, inst) < 0)
		return (-1);
	if (ft_getopcode(&line, inst) < 0)
		return (-1);
	if (ft_getparams(&line, inst) < 0)
		return (-1);
///	if (check_endline(line) < 0)
	//	return (-1);
	if (update_progsize(head, inst) < 0)
		return (-1);
	return (1);
}
