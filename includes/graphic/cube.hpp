/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:52:15 by baurens           #+#    #+#             */
/*   Updated: 2019/11/18 21:44:47 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "camera.hpp"

class cube
{
private:
	GLuint	_vbo;
	GLuint	_cbo;
	GLuint	_shader;
	GLuint	_matrixPos;

public:
	cube(void);
	~cube();

	void	render(camera &cam);
};

