/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:38:10 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/13 15:35:48 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "viewer.h"

class	window
{
	const std::string	title;
	int					width;
	int					height;

	bool				run;
	SDL_Event			events;

	SDL_Window			*win;
	SDL_GLContext		context;

public:
	window(const std::string &ti, int w, int h);
	~window(void);

	void	loop(void);
};
