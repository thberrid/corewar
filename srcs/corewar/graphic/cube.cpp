/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:00:33 by baurens           #+#    #+#             */
/*   Updated: 2019/11/22 08:25:35 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "shader.hpp"
#include "cube.hpp"

cube::cube()
{
	/*
		// cube vertex/colors list
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

		// cube faces list
		{
			front:  {-1, -1, -1}, {-1,  1, -1}, { 1,  1, -1}, { 1, -1, -1} // red
			back:   {-1, -1,  1}, {-1,  1,  1}, { 1,  1,  1}, { 1, -1,  1} // magenta
			top:    {-1,  1, -1}, {-1,  1,  1}, { 1,  1, -1}, { 1,  1,  1} // yellow
			bottom: {-1, -1, -1}, {-1, -1,  1}, { 1, -1, -1}, { 1, -1,  1} // blue
			right:  { 1,  1, -1}, { 1,  1,  1}, { 1, -1, -1}, { 1, -1,  1} // green
			left:   {-1,  1, -1}, {-1,  1,  1}, {-1, -1, -1}, {-1, -1,  1} // cyan
		}
	*/
	const float	v[108] = {
		// back
		0.5f, -0.5f, -0.5f,		-0.5f, 0.5f, -0.5f,		0.5f, 0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,		-0.5f, -0.5f, -0.5f,	-0.5f, 0.5f, -0.5f,

		// right
		-0.5f, -0.5f, -0.5f,	-0.5f, 0.5f, 0.5f,		-0.5f, 0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,	-0.5f, -0.5f, 0.5f,		-0.5f, 0.5f, 0.5f,

		// face
		-0.5f, -0.5f, 0.5f,		0.5f, 0.5f, 0.5f,		-0.5f, 0.5f, 0.5f,
		-0.5f, -0.5f, 0.5f,		0.5f, -0.5f, 0.5f,		0.5f, 0.5f, 0.5f,

		// left
		0.5f, -0.5f, 0.5f,		0.5f, 0.5f, -0.5f,		0.5f, 0.5f, 0.5f,
		0.5f, -0.5f, 0.5f,		0.5f, -0.5f, -0.5f,		0.5f, 0.5f, -0.5f,

		// top
		0.5f, 0.5f, -0.5f,		-0.5f, 0.5f, 0.5f,		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, -0.5f,		-0.5f, 0.5f, -0.5f,		-0.5f, 0.5f, 0.5f,

		// botom
		0.5f, -0.5f, 0.5f,		-0.5f, -0.5f, -0.5f,	0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, 0.5f,		-0.5f, -0.5f, 0.5f,		-0.5f, -0.5f, -0.5f,
	};

	const float	c[108] = {
		1.0f, 0.5f, 0.5f,		1.0f, 0.5f, 0.5f,		1.0f, 0.5f, 0.5f,
		1.0f, 0.5f, 0.5f,		1.0f, 0.5f, 0.5f,		1.0f, 0.5f, 0.5f,
		
		0.5f, 1.0f, 0.5f,		0.5f, 1.0f, 0.5f,		0.5f, 1.0f, 0.5f,
		0.5f, 1.0f, 0.5f,		0.5f, 1.0f, 0.5f,		0.5f, 1.0f, 0.5f,

		0.5f, 0.5f, 1.0f,		0.5f, 0.5f, 1.0f,		0.5f, 0.5f, 1.0f,
		0.5f, 0.5f, 1.0f,		0.5f, 0.5f, 1.0f,		0.5f, 0.5f, 1.0f,

		0.5f, 1.0f, 1.0f,		0.5f, 1.0f, 1.0f,		0.5f, 1.0f, 1.0f,
		0.5f, 1.0f, 1.0f,		0.5f, 1.0f, 1.0f,		0.5f, 1.0f, 1.0f,

		1.0f, 1.0f, 0.5f,		1.0f, 1.0f, 0.5f,		1.0f, 1.0f, 0.5f,
		1.0f, 1.0f, 0.5f,		1.0f, 1.0f, 0.5f,		1.0f, 1.0f, 0.5f,

		1.0f, 0.5f, 1.0f,		1.0f, 0.5f, 1.0f,		1.0f, 0.5f, 1.0f,
		1.0f, 0.5f, 1.0f,		1.0f, 0.5f, 1.0f,		1.0f, 0.5f, 1.0f,
	};

	for (int i = 0; i < 108; ++i)
	{
		_vertex[i] = v[i];
		_colors[i] = c[i];
	}

	vSize = sizeof(float) * 108;
	cSize = sizeof(float) * 108;
}

cube::~cube()
{
	if (glIsVertexArray(_vao))
		glDeleteVertexArrays(1, &_vao);
	if (glIsBuffer(_vbo))
		glDeleteBuffers(1, &_vbo);
	if (glIsShader(_shader))
		glDeleteShader(_shader);
}

void	cube::init(void)
{
	if (glIsVertexArray(_vao))
		glDeleteVertexArrays(1, &_vao);
	if (glIsBuffer(_vbo))
		glDeleteBuffers(1, &_vbo);
	if (glIsShader(_shader))
		glDeleteShader(_shader);

	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, vSize + cSize, nullptr, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, vSize, _vertex);
	glBufferSubData(GL_ARRAY_BUFFER, vSize, cSize, _colors);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	_shader = loadShaders("assets/shaders/cube.vert", "assets/shaders/cube.frag");
	_modelViewMatrixUniform = glGetUniformLocation(_shader, "modelViewMatrix");

	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);
	
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *)vSize);
			glEnableVertexAttribArray(1);
		
		glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

void	cube::render(camera &cam, glm::mat4 transform) const
{
	glm::mat4 mvp = cam.projection() * cam.getMatrix() * transform;

	glUseProgram(_shader);
	glBindVertexArray(_vao);
	glUniformMatrix4fv(_modelViewMatrixUniform, 1, GL_FALSE, &mvp[0][0]);
	glDrawArrays(GL_TRIANGLES, 0, 3*12);
	glBindVertexArray(0);
	glUseProgram(0);
}
