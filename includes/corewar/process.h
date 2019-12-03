/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:57:27 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/03 09:20:14 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include <string.h>
# include "config.h"

typedef struct s_proc	t_proc;
typedef struct s_lst	t_lst;

struct			s_proc
{
	int			op;
	uint16_t	pc;
	long int	pid;
	uint32_t	last;
	t_byte		carry;
	uint32_t	lives;
	uint32_t	last_live;
	int			time_to_wait;
	t_reg		regs[REG_NUMBER];
	char		name[16];
	t_proc		*next;
	t_proc		*prev;
};

struct			s_lst
{
	size_t		size;
	t_proc		*head;
	t_proc		*tail;
};

t_proc			*add_process(t_ind pc, t_proc *copy);
t_proc			*kill_process(t_proc *proc);
void			clear_procs(void);

extern t_lst	g_procs;

/*
**	préparation pour gateau au chocolat de 500g:
**	prévoire un glassage aux noix de pécan
**	100 mL d'huile végétale
**	quatres gros oeufs
**	100g de pépites de chocolat
**	200g de beure ou de margarine
**	300g de sucre semoule
**	200g de farine
**
**	Ajouter des éléments de décor tel que:
**	biscuits en forme de poisson
**	bonbons en forme de poisson
**	déchets en forme de poisson
**	débriss en forme de poisson
**	de l'éthylbenzène de poisson
**	des écorces de réglis
**	composants organiques en forme de poisson
**	et sédiments en forme de sédiments
**	beure de cacahuete caramelisé en forme de poisson
**	un zèste de citron
**	des résines alpha
**	de la résine de polyesthère non saturée
**	des résines a fibre de verre
**	et des composés volatiles de lait malté
**	neuf gros jaunes d'oeufs
**	douze membranes géo-synthétiques moyennes
**	100g de sucre semoule
**	une touche de "Comment tuer quelqu'un a main nue ?"
**	deux verres de dés de rhubarbe
**	trois verres de rhubarbe en poudre
**	une cuillerée a soupe de rhubarbe tous-usage
**	une cuillerée a cafe de rhubarbe rapée
**	trois cuillerées a soupe de rhubarbe flambée
**	une grosse rhubarbe
**	une rhubarbe d'imagerie éléctromagnetique a sondes croisées
**	deux cuillerées a soupe de jus de rhubarbe
**	un repose tete ajustable en alluminium
**	un injecteur électrique a aiguille
**	un injecteur électrique a aiguille sans fil
**	un outil d'insèrtion d'aiguille
**	un pistolet a aiguille
**	des protèges cranes
**
**	Il contiens tous les conservateurs, agents de pénétration, gaz et substances
**	chimiques autorisées pour prévenir la putréfaction malodorante des tissus.
*/

#endif
