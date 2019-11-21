/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:07:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/21 19:39:21 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "SDL2/SDL_image.h"
#include "SDL2/SDL.h"
#include "texture.hpp"

GLenum getInternalFormat(SDL_Surface *s)
{
	char	i = (s->format->BytesPerPixel - 3);

	/*if (s->format->BytesPerPixel == 3)
		return (GL_RGB);
	else if (s->format->BytesPerPixel == 4)
		return (GL_RGBA);
	else
		return (0);*/
	if (i <= 1)
		return (GL_RGB + i);
	return (0);
}

GLenum getFormat(SDL_Surface *s, GLenum &Internal)
{
	char	i = (s->format->BytesPerPixel - 3);

	/*if (s->format->BytesPerPixel == 3)
		return (s->format->Rmask == 0xff ? GL_RGB : GL_BGR);
	else
		return (s->format->Rmask == 0xff ? GL_RGBA : GL_BGRA);*/
	return (((s->format->Rmask == 0xff) ? GL_RGB : GL_BGR) + i);
}

GLuint loadTexture(const char *file_path, GLint minFilter, GLint magFilter)
{
	SDL_Surface	*surface;

	GLuint		textureId(0);
	GLenum		internal(0);
	GLenum		format(0);

	if (!(surface = IMG_Load(file_path)))
	{
		std::cout << "error: " << SDL_GetError() << std::endl;
		return (0);
	}
	if (!(internal = getInternalFormat(surface)))
	{
		std::cout << "error: unknown image format" << std::endl;
		SDL_FreeSurface(surface);
		return (0);
	}
	format = getFormat(surface, internal);

	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
		glTexImage2D(GL_TEXTURE_2D, 0, internal, surface->w, surface->h, 0, format, GL_UNSIGNED_BYTE, surface->pixels);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
	glBindTexture(GL_TEXTURE_2D, 0);
	SDL_FreeSurface(surface);
	return (textureId);
}

GLuint	loadTexture(const char *file_path)
{
	return (loadTexture(file_path, GL_LINEAR, GL_NEAREST));
}