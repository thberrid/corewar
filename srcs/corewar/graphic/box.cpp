/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:07:31 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/21 22:17:09 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.hpp"
#include "shader.hpp"
#include "box.hpp"

box::box(void) : cube(), _texture(0)
{
	const float	uvs[72] = {
		0, 0,	1, 0,	1, 1,
		0, 0,	0, 1,	1, 1,

		0, 0,	1, 0,	1, 1,
		0, 0,	0, 1,	1, 1,

		0, 0,	1, 0,	1, 1,
		0, 0,	0, 1,	1, 1,

		0, 0,	1, 0,	1, 1,
		0, 0,	0, 1,	1, 1,

		0, 0,	1, 0,	1, 1,
		0, 0,	0, 1,	1, 1,

		0, 0,	1, 0,	1, 1,
		0, 0,	0, 1,	1, 1,
	};

	for (int i = 0; i < 72; ++i)
		_uvs[i] = uvs[i];

	uvSize = sizeof(float) * 72;
}

box::~box()
{
	cube::~cube();
	if (glIsTexture(_texture))
		glDeleteTextures(1, &_texture);
}

void	box::init(void)
{
	if (glIsVertexArray(_vao))
		glDeleteVertexArrays(1, &_vao);
	if (glIsBuffer(_vbo))
		glDeleteBuffers(1, &_vbo);
	if (glIsShader(_shader))
		glDeleteShader(_shader);
	if (glIsTexture(_texture))
		glDeleteTextures(1, &_texture);

	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, vSize + cSize + uvSize, nullptr, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, vSize, _vertex);
	glBufferSubData(GL_ARRAY_BUFFER, vSize, cSize, _colors);
	glBufferSubData(GL_ARRAY_BUFFER, vSize + cSize, uvSize, _uvs);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	_texture = loadTexture("assets/textures/woodBox.jpg");
	_shader = loadShaders("assets/shaders/box.vert", "assets/shaders/box.frag");
	_modelViewMatrixUniform = glGetUniformLocation(_shader, "modelViewMatrix");

	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);
	
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *)vSize);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (void *)(vSize + cSize));
			glEnableVertexAttribArray(2);
		
		glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

void	box::render(camera &cam, glm::mat4 transform) const
{
	//cube::render(cam, transform);
	glm::mat4 mvp = cam.projection() * cam.getMatrix() * transform;

	glUseProgram(_shader);
	glBindVertexArray(_vao);
	glUniformMatrix4fv(_modelViewMatrixUniform, 1, GL_FALSE, &mvp[0][0]);
	glBindTexture(GL_TEXTURE_2D, _texture);
	glDrawArrays(GL_TRIANGLES, 0, 3*12);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
	glUseProgram(0);
}