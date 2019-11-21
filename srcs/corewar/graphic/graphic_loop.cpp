/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_loop.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 00:25:16 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/21 16:31:24 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "window.hpp"
#include "viewer.h"

bool	escapeHandler(window &win)
{
	bool	quit(true);

	if (win.isGrabed() && !(quit = false))
		win.ungrab();
	if (win.isFullscreen() && !(quit = false))
		win.toggleFullscreen();
	if (quit)
		win.close();
	return (true);
}

bool	pHandler(window &win)
{
	if (win.isGrabed())
		win.ungrab();
	return (true);
}

bool	fullscreenHandler(window &win)
{
	win.toggleFullscreen();
	return (true);
}

bool	leftClicHandler(window &win)
{
	if (win.isGrabed())
		return (false);
	win.grab();
	return (true);
}

bool	closeHandler(window &win)
{
	win.close();
	return (true);
}

bool	loseFocus(window &win)
{
	win.ungrab();
	return (true);
}

bool	gainFocus(window &win)
{
	if (!win.isFullscreen())
		return (false);
	win.grab();
	return (true);
}

char	graphic_loop(t_vm *vm __attribute__((unused)))
{
	window	win("Corewar", 1280, 720);

	win.addKeyHandler(SDLK_p, pHandler);
	win.addKeyHandler(SDLK_ESCAPE, escapeHandler);
	win.addKeyHandler(SDLK_F11, fullscreenHandler);

	win.addWindowHandler(SDL_WINDOWEVENT_CLOSE, closeHandler);
	win.addWindowHandler(SDL_WINDOWEVENT_FOCUS_LOST, loseFocus);
	win.addWindowHandler(SDL_WINDOWEVENT_FOCUS_GAINED, gainFocus);

	win.addButtonHandler(SDL_BUTTON_LEFT, leftClicHandler);
	
	win.loop();
	return (0);
}
