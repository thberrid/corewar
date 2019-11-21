/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:37:53 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/21 19:03:38 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <vector>
#include <chrono>
#include <cstdlib>
#include <sstream>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm/gtx/transform.hpp>
#include <glm/matrix.hpp>
#include <glm/trigonometric.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "shader.hpp"
#include "window.hpp"

using namespace std::chrono_literals;

std::map<int, bool>	keys;
std::map<int, bool>	btns;

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

	SDL_SetHint(SDL_HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS, "0");
	
	//	enable keyboard grab (disable system shortcut)
	// SDL_SetHint(SDL_HINT_GRAB_KEYBOARD, "1");

	//	the app will no longer be forced on fourground when oppening on mac
	//SDL_SetHint(SDL_HINT_MAC_BACKGROUND_APP, "0");

	//	disable screen dimming when no input are pressed for a certain time on OSX
	//	NOTE: should prefer using SDL_DisableScreenSaver() instead of this hint
	//SDL_SetHint(SDL_HINT_IDLE_TIMER_DISABLED, "1");
	


	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	this->win = SDL_CreateWindow(
		this->title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		this->width,
		this->height,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
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

void	window::init(void)
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);

	cam.setAspect(((float)width / (float)height));

	_cube.init();
}

void	window::grab(void)
{
	if (isGrabed())
		return ;
	//SDL_GetMouseState(&mouse_save.x, &mouse_save.y);
	SDL_GetGlobalMouseState(&mouse_save.x, &mouse_save.y);
	SDL_SetRelativeMouseMode(SDL_TRUE);
	SDL_GetRelativeMouseState(nullptr, nullptr);
	std::cout << "Capturing mouse!" << std::endl;
}

void	window::ungrab(void)
{
	if (!isGrabed())
		return ;
	/*if (isFullscreen())
		toggleFullscreen();*/
	SDL_SetRelativeMouseMode(SDL_FALSE);
	//SDL_WarpMouseInWindow(win, mouse_save.x, mouse_save.y);
	SDL_WarpMouseGlobal(mouse_save.x, mouse_save.y);
	std::cout << "Releasing mouse!" << std::endl;
}

void	window::setSize(int w, int h)
{
	width = w;
	height = h ? h : 1;
	glViewport(0, 0, w, h);
	//w = max(width, height);
	//h = min(width, height);
	cam.setAspect((float)w / (float)(h ? h : 1));
	std::cout << "window resized to {" <<
				width << ", " << height << "}" << std::endl;
}

void	window::toggleFullscreen(void)
{
	if (SDL_GetWindowFlags(win) & SDL_WINDOW_FULLSCREEN_DESKTOP)
	{
		SDL_SetWindowFullscreen(win, 0);
		std::cout << "leaving fullscreen mode" << std::endl;
	}
	else
	{
		SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN_DESKTOP);
		std::cout << "entering fullscreen mode" << std::endl;
		grab();
	}
}

void	window::close(void)
{
	run = false;
}

void	window::addKeyHandler(int key, t_keyHandler handler)
{
	_keyHandlers[key] = handler;
}

void	window::addButtonHandler(int key, t_keyHandler handler)
{
	_buttonHandlers[key] = handler;
}

void	window::addWindowHandler(int key, t_keyHandler handler)
{
	_windowHandlers[key] = handler;
}

void	window::events()
{
	SDL_Event	event;

	while (run && SDL_PollEvent(&event))
	{
		// window resizing
		if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
		{
			setSize(event.window.data1, event.window.data2);
			continue ;
		}

		// direct event binding
		if (event.type == SDL_KEYUP && _keyHandlers.find(event.key.keysym.sym) != _keyHandlers.end())
			if (_keyHandlers[event.key.keysym.sym](*this))
				continue ;
		if (event.type == SDL_MOUSEBUTTONUP && _buttonHandlers.find(event.button.button) != _buttonHandlers.end())
			if (_buttonHandlers[event.button.button](*this))
				continue ;
		if (event.type == SDL_WINDOWEVENT && _windowHandlers.find(event.window.event) != _windowHandlers.end())
			if (_windowHandlers[event.window.event](*this))
				continue ;

		// continuous event flags
		if (event.type == SDL_KEYUP || event.type == SDL_KEYDOWN)
			keys[event.key.keysym.sym] = (event.type == SDL_KEYDOWN);
		if (event.type == SDL_MOUSEBUTTONUP || event.type == SDL_MOUSEBUTTONDOWN)
			btns[event.button.button] = (event.type == SDL_MOUSEBUTTONDOWN);
	}
}

void	window::update()
{
	if (isGrabed())
		cam.update();
}

void	window::render()
{
	glDisable(GL_CULL_FACE);
	_cube.render(cam, glm::translate(cam.pos()));
	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_CULL_FACE);
	//glm::translate(glm::vec3(20.0f, 0.0f, 20.0f));
	//glm::scale(glm::translate(glm::vec3(20.0f, 0.0f, 20.0f)), glm::vec3(10.0f, 10.0f, 10.0f));
	_cube.render(cam, glm::scale(glm::translate(glm::vec3(20.0f, 0.0f, 20.0f)), glm::vec3(10.0f, 10.0f, 10.0f)));
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
			std::stringstream ss;
			ss << title << " - [tps: " << tps << " | fps: " << fps << "]";
			SDL_SetWindowTitle(win, ss.str().c_str());
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
