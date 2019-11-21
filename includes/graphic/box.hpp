/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:45:57 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/21 21:49:37 by abaurens         ###   ########.fr       */
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
	~box(void);

	void	init(void);
	void	render(camera &cam, glm::mat4 transform) const;
};

#endif