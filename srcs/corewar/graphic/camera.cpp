/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 05:47:00 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/14 07:02:45 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.hpp"
#include <glm/gtc/matrix_transform.hpp>

camera::camera(void) : pos(0, 0, 0), rot(0, 0, 0), fov(45.0f), speed(3.0f), mouseSpeed(0.005f) {}

camera::camera(vec3 pos, vec3 rot, float fov, float speed, float mouseSpeed) : pos(pos), rot(rot), fov(fov), speed(speed), mouseSpeed(mouseSpeed) {}

camera::~camera() {}

void	camera::move(SDL_Event event)
{
	
}

mat4	camera::getMatrix(void)
{
	mat4 View = glm::lookAt(
		pos,
		rot,
		glm::vec3(0,1,0)
	);
}