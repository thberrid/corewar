/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:38:10 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/21 19:03:44 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm/vec2.hpp>
#include "camera.hpp"
#include "cube.hpp"
#include "viewer.h"

class	window;

typedef bool	(*t_keyHandler)(window &window);

class	window
{
	const std::string	title;
	int					width;
	int					height;
	bool				run;
	int					fps;
	int					tps;

	SDL_Window			*win;
	SDL_GLContext		context;
	camera				cam;
	glm::ivec2			mouse_save;
	cube				_cube;

	std::map<int, t_keyHandler>	_keyHandlers;
	std::map<int, t_keyHandler>	_buttonHandlers;
	std::map<int, t_keyHandler>	_windowHandlers;

	void	init(void);
	void	update(void);
	void	render(void);
	void	events(void);

public:
	window(const std::string &ti, int w, int h);
	~window(void);

	void	addKeyHandler(int key, t_keyHandler handler);
	void	addButtonHandler(int key, t_keyHandler handler);
	void	addWindowHandler(int key, t_keyHandler handler);

	void	loop(void);
	void	grab(void);
	void	close(void);
	void	ungrab(void);
	void	setSize(int w, int h);
	void	toggleFullscreen(void);

	bool	isGrabed(void) const { return (SDL_GetRelativeMouseMode()); }
	bool	isFullscreen(void) const { return (SDL_GetWindowFlags(win) & SDL_WINDOW_FULLSCREEN_DESKTOP); }
};
