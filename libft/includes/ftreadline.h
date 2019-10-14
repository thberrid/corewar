/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftreadline.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:41:55 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/02 13:42:09 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTREADLINE_H
# define FTREADLINE_H

char	*ft_readline(const char *prompt);
char	*ft_dreadline(const int fd, const char *prompt);

#endif
