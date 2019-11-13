/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:37:53 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/13 23:36:38 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GL_SILENCE_DEPRECATION

#include <cstdlib>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "shader.hpp"
#include "window.hpp"

window::window(const std::string &ti, int w, int h) : title(ti), width(w), height(h), run(true)
{
	std::string	err;
	GLenum		glew_status;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "error: can't initialize SDL: "
					<< SDL_GetError() << std::endl;
		SDL_Quit();
		exit(1);
	}

	// Set OpenGL version
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	// Enable Double Buffering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	//	Create Window
	this->win = SDL_CreateWindow(this->title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->width, this->height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (!this->win)
	{
		std::cerr << "error: Can't create window: "
			<< SDL_GetError() << std::endl;
		SDL_Quit();
		exit(1);
	}


	//	Create OpenGL context
	if (!(this->context = SDL_GL_CreateContext(this->win)))
	{
		std::cerr << "Can't create OpenGL context: "
				<< SDL_GetError() << std::endl;
		SDL_DestroyWindow(this->win);
		SDL_Quit();
		exit(1);
	}

	glewExperimental = GL_TRUE;
	if ((glew_status = glewInit()) != GLEW_OK)
	{
		std::cerr << "eror: Can't initialize GLEW: "
				<< glewGetErrorString(glew_status) << std::endl;
		SDL_GL_DeleteContext(this->context);
		SDL_DestroyWindow(this->win);
		SDL_Quit();
		exit(1);
	}
}

window::~window(void)
{
	SDL_GL_DeleteContext(this->context);
	SDL_DestroyWindow(this->win);
	SDL_Quit();
}

static const GLfloat g_vertex_buffer_data[] = {
	-1.0f, -1.0f,
	1.0f, -1.0f,
	0.0f,  1.0f,
};

void	window::loop(void)
{

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// This will identify our vertex buffer
	GLuint vertexbuffer;

	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);

	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	GLuint programID = LoadShaders("/Users/abaurens/Desktop/Workspace/Algo/corewar/shaders/main.vert", "/Users/abaurens/Desktop/Workspace/Algo/corewar/shaders/main.frag");
	(void)programID;
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	while (this->run)
	{
		// Recupere un evenement
		SDL_PollEvent(&this->events);
		if (this->events.window.event == SDL_WINDOWEVENT_CLOSE)
			this->run = false;
		// Nettoyage de l'écran
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Utilise le shader
		glUseProgram(programID);

		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		// bind le vbo 'vertexbuffer'
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);

		// Actualisation de la fenêtre
		SDL_GL_SwapWindow(this->win);
	}
}
