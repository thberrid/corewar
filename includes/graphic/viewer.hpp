/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baurens <baurens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 01:50:25 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/22 08:48:46 by baurens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWER_H
# define VIEWER_H

# include <map>
# include <SDL2/SDL.h>

# ifdef __cplusplus
extern "C" {
# endif

# include "vm.h"

# ifdef __cplusplus
}
# endif

# define TITLE	"Corewar"
# define WIDTH	1280
# define HEIGHT	720

extern std::map<int, bool>	keys;
extern std::map<int, bool>	btns;

# ifdef __APPLE__

#  define KEY_FRONT		SDLK_w
#  define KEY_LEFT		SDLK_a

# else

#  define KEY_FRONT		SDLK_z
#  define KEY_LEFT		SDLK_q

# endif

#  define KEY_RIGHT		SDLK_d
#  define KEY_BACK		SDLK_s
#  define KEY_DOWN		SDLK_LSHIFT
#  define KEY_UP		SDLK_SPACE

#endif
