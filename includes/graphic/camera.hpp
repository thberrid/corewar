/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 05:46:28 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/14 08:52:34 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_HPP
# define CAMERA_HPP

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

using namespace glm;

class	camera
{
private:
	vec3	pos;
	vec3	rot;
	float	fov;

	float speed;
	float mouseSpeed;

public:
	camera(void);
	camera(vec3 pos, vec3 rot, float fov, float speed, float mouseSpeed);
	~camera(void);

	void	update(void);
	mat4	getMatrix(void);
};

#endif
