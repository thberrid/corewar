/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:50:25 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/25 11:35:19 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftlib.h"

void	ft_memdel(void *ap)
{
	void	**p;

	if (!ap)
		return ;
	p = (void **)ap;
	free(*p);
	*p = NULL;
}
