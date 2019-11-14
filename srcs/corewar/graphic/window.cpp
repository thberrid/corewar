/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:37:53 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/14 07:02:20 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <chrono>
#include <cstdlib>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm/matrix.hpp>
#include <glm/trigonometric.hpp>
#include <glm/gtc/matrix_transform.hpp>
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

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	this->win = SDL_CreateWindow(
		this->title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		this->width,
		this->height,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
	);
	if (!this->win)
	{
		std::cerr << "error: Can't create window: "
			<< SDL_GetError() << std::endl;
		SDL_Quit();
		exit(1);
	}

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
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glGenVertexArrays(1, &vaoId);
	glBindVertexArray(vaoId);

	const GLfloat vertex[] = {
		-1.0f, -1.0f, -1.0f,		-1.0f, -1.0f,  1.0f,		-1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f, -1.0f,		-1.0f, -1.0f, -1.0f,		-1.0f,  1.0f, -1.0f,
		 1.0f, -1.0f,  1.0f,		-1.0f, -1.0f, -1.0f,		 1.0f, -1.0f, -1.0f,
		 1.0f,  1.0f, -1.0f,		 1.0f, -1.0f, -1.0f,		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,		-1.0f,  1.0f,  1.0f,		-1.0f,  1.0f, -1.0f,
		 1.0f, -1.0f,  1.0f,		-1.0f, -1.0f,  1.0f,		-1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f,  1.0f,		-1.0f, -1.0f,  1.0f,		 1.0f, -1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,		 1.0f, -1.0f, -1.0f,		 1.0f,  1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,		 1.0f,  1.0f,  1.0f,		 1.0f, -1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,		 1.0f,  1.0f, -1.0f,		-1.0f,  1.0f, -1.0f,
		 1.0f,  1.0f,  1.0f,		-1.0f,  1.0f, -1.0f,		-1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,		-1.0f,  1.0f,  1.0f,		 1.0f, -1.0f,  1.0f
	};
	glGenBuffers(1, &vboId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

	const GLfloat colors[] = {
		0.583f,  0.771f,  0.014f,	0.609f,  0.115f,  0.436f,	0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,	0.435f,  0.602f,  0.223f,	0.310f,  0.747f,  0.185f,
		0.597f,  0.770f,  0.761f,	0.559f,  0.436f,  0.730f,	0.359f,  0.583f,  0.152f,
		0.483f,  0.596f,  0.789f,	0.559f,  0.861f,  0.639f,	0.195f,  0.548f,  0.859f,
		0.014f,  0.184f,  0.576f,	0.771f,  0.328f,  0.970f,	0.406f,  0.615f,  0.116f,
		0.676f,  0.977f,  0.133f,	0.971f,  0.572f,  0.833f,	0.140f,  0.616f,  0.489f,
		0.997f,  0.513f,  0.064f,	0.945f,  0.719f,  0.592f,	0.543f,  0.021f,  0.978f,
		0.279f,  0.317f,  0.505f,	0.167f,  0.620f,  0.077f,	0.347f,  0.857f,  0.137f,
		0.055f,  0.953f,  0.042f,	0.714f,  0.505f,  0.345f,	0.783f,  0.290f,  0.734f,
		0.722f,  0.645f,  0.174f,	0.302f,  0.455f,  0.848f,	0.225f,  0.587f,  0.040f,
		0.517f,  0.713f,  0.338f,	0.053f,  0.959f,  0.120f,	0.393f,  0.621f,  0.362f,
		0.673f,  0.211f,  0.457f,	0.820f,  0.883f,  0.371f,	0.982f,  0.099f,  0.879f
	};
	glGenBuffers(1, &cboId);
	glBindBuffer(GL_ARRAY_BUFFER, cboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

	shaderId = LoadShaders("shaders/main.vert", "shaders/main.frag");
	matrixID = glGetUniformLocation(shaderId, "MVP");
}

void	window::events()
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)
			this->run = false;
		else
			cam.move(event);
	}
}

float	i(0.0);

void	window::update()
{
	i += 0.005;
}

void	window::render()
{
	glUseProgram(shaderId);

	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
	glm::mat4 Model = glm::mat4(1.0f);
	glm::mat4 View = glm::lookAt(
		glm::vec3(4*(cos(i)),3,4*(sin(i))),
		glm::vec3(0,0,0),
		glm::vec3(0,1,0)
	);
	glm::mat4 mvp = Projection * View * Model;

	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &mvp[0][0]);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, cboId);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3*12);

	glDisableVertexAttribArray(1);
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
