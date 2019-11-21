/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:07:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/21 20:38:34 by abaurens         ###   ########.fr       */
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

GLenum getFormat(SDL_Surface *s)
{
	char	i = (s->format->BytesPerPixel - 3);

	/*if (s->format->BytesPerPixel == 3)
		return (s->format->Rmask == 0xff ? GL_RGB : GL_BGR);
	else
		return (s->format->Rmask == 0xff ? GL_RGBA : GL_BGRA);*/
	return (((s->format->Rmask == 0xff) ? GL_RGB : GL_BGR) + i);
}

SDL_Surface	*flipImage(SDL_Surface *src)
{
	SDL_Surface 	*res;
	unsigned char	*pixSrc;
	unsigned char	*pixRes;
	
	if (!(res = SDL_CreateRGBSurface(0,
		src->w, src->h,
		src->format->BitsPerPixel,
		src->format->Rmask,
		src->format->Gmask,
		src->format->Bmask,
		src->format->Amask)))
		return (nullptr);
	
	pixSrc = (unsigned char *)src->pixels;
	pixRes = (unsigned char *)res->pixels;
	// Inversion des pixels

	for(int i = 0; i < src->h; i++)
		for(int j = 0; j < src->w * src->format->BytesPerPixel; j++)
			pixRes[(src->w * src->format->BytesPerPixel * (src->h - 1 - i)) + j] = pixSrc[(src->w * src->format->BytesPerPixel * i) + j];
	return (res);
}

GLuint loadTexture(const char *file_path, GLint minFilter, GLint magFilter)
{
	SDL_Surface	*surface(nullptr);
	SDL_Surface	*inv(nullptr);

	GLuint		textureId(0);
	GLenum		internal(0);
	GLenum		format(0);

	if (!(surface = IMG_Load(file_path)) || !(inv = flipImage(surface)))
	{
		if (surface)
			SDL_FreeSurface(surface);
		std::cout << "error: " << SDL_GetError() << std::endl;
		return (0);
	}
	SDL_FreeSurface(surface);
	if (!(internal = getInternalFormat(inv)))
	{
		std::cout << "error: unknown image format" << std::endl;
		SDL_FreeSurface(inv);
		return (0);
	}
	format = getFormat(inv);

	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
		glTexImage2D(GL_TEXTURE_2D, 0, internal, inv->w, inv->h, 0, format, GL_UNSIGNED_BYTE, inv->pixels);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
	glBindTexture(GL_TEXTURE_2D, 0);
	SDL_FreeSurface(inv);
	return (textureId);
}

GLuint	loadTexture(const char *file_path)
{
	return (loadTexture(file_path, GL_LINEAR, GL_NEAREST));
}