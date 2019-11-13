/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_loop.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 00:25:16 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/13 13:49:41 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "viewer.h"
#include "vm.h"

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

void			quit_sdl(SDL_Window *window, SDL_GLContext gl_context)
{
	SDL_GL_DeleteContext(gl_context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

char			graphic_loop(t_vm *vm __attribute__((unused)))
{
	SDL_Window		*window(0);
	SDL_GLContext	gl_context(0);
	SDL_Event		events;
	bool			loop(true);

	//enter graphic part
	if (!(window = init_sdl(TITLE, WIDTH, HEIGTH)))
		return (1);
	if (!(gl_context = init_opengl(window)))
		return (1);

	GLenum	initialisationGLEW(glewInit());

	if (initialisationGLEW != GLEW_OK)
	{
		// On affiche l'erreur grâce à la fonction : glewGetErrorString(GLenum code)
		std::cout << "Erreur d'initialisation de GLEW : " << glewGetErrorString(initialisationGLEW) << std::endl;

		// On quitte la SDL
		SDL_GL_DeleteContext(gl_context);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return (1);
	}

	// vertex array
	float vertices[] = {-0.5, -0.5,   0.0, 0.5,   0.5, -0.5};


	//Main loop
	while (loop)
	{
		SDL_PollEvent(&events);

		if (events.window.event == SDL_WINDOWEVENT_CLOSE)
			loop = false;

		// Nettoyage de l'écran
		glClear(GL_COLOR_BUFFER_BIT);


		// On remplie puis on active le tableau Vertex Attrib 0
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);
		glEnableVertexAttribArray(0);


		// On affiche le triangle
		glDrawArrays(GL_TRIANGLES, 0, 3);


		// On désactive le tableau Vertex Attrib puisque l'on n'en a plus besoin
		glDisableVertexAttribArray(0);


		// Actualisation de la fenêtre
		SDL_GL_SwapWindow(window);
	}

	//exit graphic part
	quit_sdl(window, gl_context);
	return (0);
}
