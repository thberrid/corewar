/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:38:10 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/18 21:53:19 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm/vec2.hpp>
#include "camera.hpp"
#include "cube.hpp"
#include "viewer.h"

class	window
{
	const std::string	title;
	int					width;
	int					height;
	bool				run;
	int					fps;
	int					tps;

	GLuint				vaoId;
	/*
	GLuint				vboId;
	GLuint				cboId;
	GLuint				shaderId;
	GLuint				matrixID;
	*/
	SDL_Window			*win;
	SDL_GLContext		context;
	camera				cam;
	glm::ivec2			mouse_save;
	cube				*_cube;

	void	init(void);
	void	update(void);
	void	render(void);
	void	events(void);

public:
	window(const std::string &ti, int w, int h);
	~window(void);

	void	loop(void);
};
