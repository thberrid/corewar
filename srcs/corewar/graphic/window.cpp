/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:37:53 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/14 02:38:15 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <chrono>
#include <cstdlib>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "shader.hpp"
#include "window.hpp"

using namespace std::chrono_literals;

constexpr std::chrono::seconds		secstep(1s);
constexpr std::chrono::nanoseconds	timestep(16666666ns);

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

void	window::init()
{
	glGenVertexArrays(1, &vaoId);
	glBindVertexArray(vaoId);

	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vboId);

	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vboId);

	// TODO: remove this piece of shit !
	const GLfloat vertex[] = {
		-1.0f, -1.0f,
		1.0f, -1.0f,
		0.0f,  1.0f,
	};
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

	shaderId = LoadShaders("shaders/main.vert", "shaders/main.frag");
}

void	window::events()
{
	SDL_Event	events;

	while (SDL_PollEvent(&events))
	{
		if (events.window.event == SDL_WINDOWEVENT_CLOSE)
			this->run = false;
	}
}

void	window::update()
{
	
}

void	window::render()
{
	glUseProgram(shaderId);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
}

void	window::loop(void)
{
	std::chrono::nanoseconds	lag(0ns);
	std::chrono::seconds		sec(0s);

	using	clock = std::chrono::high_resolution_clock;

	init();
	auto time_start = clock::now();
	auto sec_start = time_start;
	while (this->run)
	{
		auto delta_time = clock::now() - time_start;
		time_start = clock::now();
		sec = std::chrono::duration_cast<std::chrono::seconds>(time_start - sec_start);
		lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);
		
		events();
		if (sec >= secstep)
		{
			std::cout << "[tps: " << tps << " | fps: " << fps << "]" << std::endl;
			sec_start = clock::now();
			fps = 0;
			tps = 0;
		}
		while (lag >= timestep)
		{
			++tps;
			lag -= timestep;
			update();
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		++fps;
		render();
		SDL_GL_SwapWindow(this->win);
	}
}
