/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 05:37:19 by baurens           #+#    #+#             */
/*   Updated: 2019/11/25 06:14:19 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.hpp"

transform::transform(void) : _pos(0), _rot(0), _scale(1) {}

transform::transform(vec3 pos, vec3 rot, vec3 scale) : _pos(pos), _rot(rot), _scale(scale) {}

transform::~transform() {}

void	transform::setPos(vec3 pos)
{
	_pos = pos;
}

void	transform::setRot(vec3 rot)
{
	_rot = rot;
}

void	transform::setScale(vec3 scale)
{
	_scale = scale;
}

void	transform::setPos(float x, float y, float z)
{
	_pos.x = x;
	_pos.y = y;
	_pos.z = z;
}

void	transform::setRot(float x, float y, float z)
{
	_rot.x = x;
	_rot.y = y;
	_rot.z = z;
}

void	transform::setScale(float x, float y, float z)
{
	_scale.x = x;
	_scale.y = y;
	_scale.z = z;
}