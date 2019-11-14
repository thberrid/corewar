/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 05:47:00 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/14 08:57:10 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "viewer.h"
#include "camera.hpp"
#include <SDL2/SDL.h>
#include <glm/gtc/matrix_transform.hpp>

camera::camera(void) : pos(0, 0, 0), rot(0, 0, 0), fov(45.0f), speed(3.0f), mouseSpeed(0.005f) {}

camera::camera(vec3 pos, vec3 rot, float fov, float speed, float mouseSpeed) : pos(pos), rot(rot), fov(fov), speed(speed), mouseSpeed(mouseSpeed) {}

camera::~camera() {}

void	camera::update(void)
{
	if (keys[SDLK_z])
		std::cout << "FORWARD" << std::endl;
	if (keys[SDLK_s])
		std::cout << "BACKWARD" << std::endl;
	if (keys[SDLK_d])
		std::cout << "RIGHT" << std::endl;
	if (keys[SDLK_q])
		std::cout << "LEFT" << std::endl;
}

mat4	camera::getMatrix(void)
{
	return (glm::lookAt(pos, rot, glm::vec3(0,1,0)));
}
