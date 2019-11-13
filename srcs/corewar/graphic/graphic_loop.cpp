/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_loop.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 00:25:16 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/13 17:47:26 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "window.hpp"
#include "viewer.h"

char	graphic_loop(t_vm *vm __attribute__((unused)))
{
	window	win("Corewar", 1280, 720);
	win.loop();
	return (0);
}
