/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:09:37 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/20 06:25:40 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLIB_H
# define FTLIB_H

# include <string.h>
# include <inttypes.h>

# include "ftio.h"

void		ft_strclr(char *s);
void		ft_memdel(void *ap);
void		ft_strdel(char **as);
void		ft_bzero(void *s, size_t n);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

char		ft_isalpha(int c);
char		ft_isdigit(int c);
char		ft_islower(int c);
char		ft_isupper(int c);
char		ft_isalnum(int c);
char		ft_isascii(int c);
char		ft_isprint(int c);
char		ft_isnumber(const char *str);
char		ft_isnumber_base(const char *str, const char *base);
char		ft_isbase(const char *base);
char		ft_contains(char c, const char *str);
char		ft_strequ(char const *s1, char const *s2);
char		ft_strcmp(const char *s1, const char *s2);
char		ft_memcmp(const void *s1, const void *s2, size_t n);
char		ft_strncmp(const char *s1, const char *s2, size_t n);
char		ft_strnequ(char const *s1, char const *s2, size_t n);

int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_isspace(int c);

size_t		ft_strlen(const char *str);
size_t		ft_numlen(long int nb);
size_t		ft_unsignedlen(uintmax_t nb);
size_t		ft_idxof(const char c, register const char *str);
size_t		ft_count_words(const char *str, const char *sep);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_unsignedlen_base(uintmax_t n, const char *base);

void		*ft_memalloc(size_t size);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, const size_t len);

char		*ft_strnew(size_t size);
char		*ft_strupcase(char *str);
char		*ft_strtrim(char const *s);
char		*ft_strdup(const char *src);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strndup(const char *str, size_t len);
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
char		*ft_strmcat(const char *s1, const char *s2, int n);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strnstr(const char *s1, const char *s2, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strsub(char const *s, unsigned int start, size_t len);

char		**ft_strsplit(char const *s, char c);
char		**ft_split(char const *str, char const *sep);

uintptr_t	ft_freturn(void *ptr, uintptr_t ret);

char		match(const char *s1, const char *s2);

#endif
