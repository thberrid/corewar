/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcipher.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:00:35 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/15 01:09:59 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTCIPHER_H
# define FTCIPHER_H

# include <inttypes.h>
# include <string.h>

# define MAGIC ((uint8_t)170)

/*
**	Cipher the memory chunk pointed by src of size [size]
**
**	Returns the ciphered version of size [size * 2].
**
**	Notes:
**	- The returned pointer need to be free(3) by the user
**		once he's done using it.
*/
void	*ft_cipher(const void *src, const size_t size);

/*
**	Decipher and store the memory chunk pointed by data of size [size]
**		inside the memory chunk pointed to by dest.
**
**	Dest needs to be at least size / 2 bytes long to be
**		able to store the result.
**
**	returns true upon success and false if the data
**		to be deciphered are uncompatible.
**
**	Notes:
**	- This function does NOT free(3) the data pointer for the user.
**	- This function is overlap safe, which means it can decode and store
**		the result in overlaping memory spaces
*/
uint8_t	ft_decipher(const void *data, void *dest, size_t size);

#endif
