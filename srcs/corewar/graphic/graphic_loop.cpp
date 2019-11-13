/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_loop.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 00:25:16 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/13 15:38:22 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "window.hpp"
#include "viewer.h"
#include "vm.h"

/*
SDL_Window		*init_sdl(const char *title, const int width, const int height)
{
	SDL_Window	*res;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
		SDL_Quit();
		return (nullptr);
	}
	if (!(res = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL)))
	{
	    std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl;
	    SDL_Quit();
	    return (nullptr);
	}
	return (res);
}

SDL_GLContext	init_opengl(SDL_Window *window)
{
	SDL_GLContext	res;

	// Version d'OpenGL
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	// Double Buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	if (!(res = SDL_GL_CreateContext(window)))
	{
		std::cout << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return (res);
	}
	return (res);
}
*/

void			quit_sdl(SDL_Window *window, SDL_GLContext gl_context)
{
	SDL_GL_DeleteContext(gl_context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

char			graphic_loop(t_vm *vm __attribute__((unused)))
{
	window	*win;
	try {
		win = new window("Corewar", 1280, 720);
	} catch (std::string e) {
		std::cerr << "\e[31merror\e[0m: " << e << std::endl;
		return (1);
	}
	win->loop();
	delete (win);
	return (0);
}
