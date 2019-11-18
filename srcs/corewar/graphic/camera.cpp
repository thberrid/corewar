/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 05:47:00 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/18 13:10:48 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <SDL2/SDL.h>
#include <glm/gtc/matrix_transform.hpp>
#include "ftmath.h"
#include "viewer.h"
#include "camera.hpp"

camera::camera(void) : _pos(0, 0, -5), _rot(0, 0), _fov(45.0f), _speed(0.75f), _mouseSpeed(0.005f) {}

camera::camera(vec3 pos, vec2 rot, float fov, float speed, float mouseSpeed) : _pos(pos), _rot(rot), _fov(fov), _speed(speed), _mouseSpeed(mouseSpeed) {}

camera::~camera() {}

vec3	camera::up(void) const
{
	return (glm::cross(right(), forward()));
}

vec3	camera::right(void) const
{
	return (vec3(sin(_rot.y - FT_HPI), 0, cos(_rot.y - FT_HPI)));
}

vec3	camera::forward(void) const
{
	return (vec3(cos(_rot.x) * sin(_rot.y), sin(_rot.x), cos(_rot.x) * cos(_rot.y)));
}

void	camera::update(void)
{
	vec2	rot(0, 0);
	vec3	dir(0, 0, 0);
	vec3	front = normalize(vec3(forward().x + up().x, 0, forward().z + up().z));

	if (keys[SDLK_d]) dir += right();
	if (keys[SDLK_q]) dir -= right();
	if (keys[SDLK_z]) dir += front;
	if (keys[SDLK_s]) dir -= front;
	if (keys[SDLK_SPACE]) dir.y++;
	if (keys[SDLK_LSHIFT]) dir.y--;

	if (keys[SDLK_LEFT]) ++rot.y;
	if (keys[SDLK_RIGHT]) --rot.y;
	if (keys[SDLK_UP]) ++rot.x;
	if (keys[SDLK_DOWN]) --rot.x;

	if ((abs(dir.x) + abs(dir.y) + abs(dir.z)) != 0.0)
		_pos += (normalize(dir) * _speed);
	if ((abs(rot.x) + abs(rot.y)) != 0.0)
		_rot += (normalize(rot) * _mouseSpeed);
}

mat4	camera::getMatrix(void)
{
	return (glm::lookAt(_pos, _pos + forward(), up()));
}

void	camera::setRot(vec2 r)
{
	_rot.x = r.x;
	_rot.y = r.y;
}

void	camera::setRot(float x, float y)
{
	_rot.x = x;
	_rot.y = y;
}

void	camera::setPos(vec3 p)
{
	_pos.x = p.x;
	_pos.y = p.y;
	_pos.z = p.z;
}

void	camera::setPos(float x, float y, float z)
{
	_pos.x = x;
	_pos.y = y;
	_pos.z = z;
}
