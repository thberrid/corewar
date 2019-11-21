/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:52:15 by baurens           #+#    #+#             */
/*   Updated: 2019/11/20 21:51:39 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "camera.hpp"

class cube
{
private:

protected:
	float	_vertex[108];
	float	_colors[108];

	GLuint	_vbo;
	GLuint	_vao;
	GLuint	_shader;
	GLuint	_modelViewMatrixUniform;

public:
	cube(void);
	~cube();

	void	init(void);
	void	render(camera &cam, glm::mat4 transform);
};

