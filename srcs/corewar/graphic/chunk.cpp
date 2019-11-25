/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:25:46 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/25 15:14:09 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.hpp"
#include "viewer.hpp"

chunk::chunk(void) : _angle(0.0f), _time(0.0f), _color(0.3, 0.3, 0.3) {}

chunk::~chunk() {}

void	chunk::setColor(glm::vec3 color)
{
	_color = color;
}

void	chunk::setColor(float r, float g, float b)
{
	_color.x = r;
	_color.y = g;
	_color.z = b;
}

void	chunk::changeColor(glm::vec3 color)
{
	_futureColors.push(color);
}

void	chunk::changeColor(float r, float g, float b)
{
	_futureColors.push(vec3(r, g, b));
}

void	chunk::setPos(vec3 pos)
{
	_transform.setPos(pos);
}

void	chunk::setRot(vec3 rot)
{
	_transform.setRot(rot);
}

void	chunk::setScale(vec3 scale)
{
	_transform.setScale(scale);
}

void	chunk::setPos(float x, float y, float z)
{
	_transform.setPos(x, y, z);
}

void	chunk::setRot(float x, float y, float z)
{
	_transform.setRot(x, y, z);
}

void	chunk::setScale(float x, float y, float z)
{
	_transform.setScale(x, y, z);
}

void	chunk::update(void)
{
	if (!_futureColors.empty())
	{
		if (_time <= ANIM)
		{
			_time += (1.0f / TPS);
			_angle = (180.0f * (_time / ANIM));
		}
		else
		{
			_time = 0.0f;
			_angle = 0.0f;
			_color = _futureColors.front();
			_futureColors.pop();
		}
	}
}
