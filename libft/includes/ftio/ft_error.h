/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 18:28:58 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 14:15:58 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# define ERROR_MSG_MAX_LEN	255

# if (defined (__MACH__) && defined (__APPLE__))
#  define FT_EUNDEFINED 0
# else
#  define FT_ESUCCESS 0
# endif

# define FT_ESUCCESS_MSG	"Success"
# define FT_EUNDEF_MSG		"Undefined error: 0"

# define FT_EUNKOWN_LEN		14
# define FT_EUNKOWN_MSG		"Unknown error "

int		get_errno(void) __attribute__((visibility("internal")));
void	ft_perror(const char *str);
char	*ft_strerror(const int errnum);

#endif
