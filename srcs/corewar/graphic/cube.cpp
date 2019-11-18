/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:00:33 by baurens           #+#    #+#             */
/*   Updated: 2019/11/18 21:52:50 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.hpp"
#include "shader.hpp"

cube::cube()
{
	/*	// cube bertex list
		{
			{-0.5, -0.5, -0.5},
			{-0.5, -0.5, +0.5},
			{+0.5, -0.5, +0.5},
			{+0.5, -0.5, -0.5},
			{-0.5, +0.5, -0.5},
			{-0.5, +0.5, +0.5},
			{+0.5, +0.5, +0.5},
			{+0.5, +0.5, -0.5},
		}
	*/
	const float	vertex[] = {
		-0.5f, -0.5f, -0.5f,		-0.5f, -0.5f,  0.5f,		-0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f, -0.5f,		-0.5f, -0.5f, -0.5f,		-0.5f,  0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,		-0.5f, -0.5f, -0.5f,		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,		 0.5f, -0.5f, -0.5f,		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,		-0.5f,  0.5f,  0.5f,		-0.5f,  0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,		-0.5f, -0.5f,  0.5f,		-0.5f, -0.5f, -0.5f,
		-0.5f,  0.5f,  0.5f,		-0.5f, -0.5f,  0.5f,		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,		 0.5f, -0.5f, -0.5f,		 0.5f,  0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,		 0.5f,  0.5f,  0.5f,		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,		 0.5f,  0.5f, -0.5f,		-0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f,  0.5f,		-0.5f,  0.5f, -0.5f,		-0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,		-0.5f,  0.5f,  0.5f,		 0.5f, -0.5f,  0.5f
	};
	const float	colors[] = {
		0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f,	0.5f,  0.5f,  0.5f
	};

	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

	glGenBuffers(1, &_cbo);
	glBindBuffer(GL_ARRAY_BUFFER, _cbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

	_shader = LoadShaders("assets/shaders/cube.vert", "assets/shaders/cube.frag");
	_matrixPos = glGetUniformLocation(_shader, "MVP");
}

cube::~cube() {}

void	cube::render(camera &cam)
{
	glm::mat4 Model = glm::mat4(1.0f);
	glm::mat4 mvp = cam.projection() * cam.getMatrix() * Model;

	glUseProgram(_shader);

	glUniformMatrix4fv(_matrixPos, 1, GL_FALSE, &mvp[0][0]);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, _cbo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3*12);

	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
}