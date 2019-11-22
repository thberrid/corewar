/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:45:57 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/22 08:25:22 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOX_HPP
# define BOX_HPP

#include "cube.hpp"

class box : cube
{
private:
	GLuint	_texture;
	float	_uvs[72];

	size_t	uvSize;
	
public:
	box(void);
	~box();

	void	init(void);
	void	render(camera &cam, glm::mat4 transform) const;
};

#endif