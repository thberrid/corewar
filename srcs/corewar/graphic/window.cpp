/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:37:53 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/13 15:38:31 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.hpp"

window::window(const std::string &ti, int w, int h) : title(ti), width(w), height(h), run(true)
{
	std::string	err;
	GLenum		glew_status;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		err = "can't initialize SDL: ";
		err += SDL_GetError();
		SDL_Quit();
		throw (err);
	}

	// Set OpenGL version
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	// Enable Double Buffering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	//	Create Window
	this->win = SDL_CreateWindow(this->title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->width, this->height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (!this->win)
	{
		err = "Can't create window: ";
		err += SDL_GetError();
		SDL_Quit();
		throw (err);
	}

	//	Create OpenGL context
	if (!(this->context = SDL_GL_CreateContext(this->win)))
	{
		err = "Can't create OpenGL context: ";
		err += SDL_GetError();
		SDL_DestroyWindow(this->win);
		SDL_Quit();
		throw (err);
	}

	if ((glew_status = glewInit()) != GLEW_OK)
	{
		err = "can't initialize GLEW: ";
		err += (const char *)glewGetErrorString(glew_status);
		SDL_GL_DeleteContext(this->context);
		SDL_DestroyWindow(this->win);
		SDL_Quit();
		throw (err);
	}
}

window::~window(void)
{
	SDL_GL_DeleteContext(this->context);
	SDL_DestroyWindow(this->win);
	SDL_Quit();
}

void	window::loop(void)
{
	float vertices[] = {0.0, 0.0,   0.5, 0.0,   0.0, 0.5,      // Triangle 1
					-0.8, -0.8,   -0.3, -0.8,   -0.8, -0.3};   // Triangle 2

	while (this->run)
	{
		SDL_PollEvent(&this->events);
		if (this->events.window.event == SDL_WINDOWEVENT_CLOSE)
			this->run = false;

		// Nettoyage de l'écran
		glClear(GL_COLOR_BUFFER_BIT);

		// On remplie puis on active le tableau Vertex Attrib 0
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);
		glEnableVertexAttribArray(0);

		// On affiche le triangle
		glDrawArrays(GL_TRIANGLES, 0, 6);

		// On désactive le tableau Vertex Attrib puisque l'on n'en a plus besoin
		glDisableVertexAttribArray(0);

		// Actualisation de la fenêtre
		SDL_GL_SwapWindow(this->win);
	}
}
