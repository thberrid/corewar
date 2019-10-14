/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 02:16:52 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 14:17:51 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <string.h>

# ifndef GNL_BUF
#  define GNL_BUF	1024
# endif

typedef struct s_gnl_e	t_gnl_e;
typedef struct s_gnl	t_gnl;

struct		s_gnl_e
{
	int		fd;
	char	*sv;
	t_gnl_e	*next;
};

struct		s_gnl
{
	size_t	size;
	t_gnl_e	*head;
};

/*
**	utils functions
*/
char		*gnl_cat_(const char *s1, const char *s2,
					int n) __attribute__((visibility("internal")));
char		gnl_rd_check_(const char *buf, size_t size,
					const char *crset) __attribute__((visibility("internal")));

/*
**	get next line core functions
*/
char		fdline_(const int fd, char **line,
				char **save) __attribute__((visibility("internal")));
char		sfdline_(const int fd, char **line,
				char **save) __attribute__((visibility("internal")));
char		cfdline_(const int fd, char **line, char **save,
				const char *crset) __attribute__((visibility("internal")));

/*
**	get next line buffer function
**
**	these functions gives access to the internal buffer list of gnl.
**	gnl_flush and gnl_clear will be prototyped in ftio.h as well because
**	calling them can be usefull to avoid memory leaks...
*/

t_gnl		*get_gnl_bufer_list(void) __attribute__((visibility("internal")));
t_gnl_e		*get_gnl_bufer(
				const int fd) __attribute__((visibility("internal")));
void		gnl_flush_elem(
				const t_gnl_e *to_rm) __attribute__((visibility("internal")));

/*
**	avoid re-defining those prototypes if they already exist
*/
# ifndef FTIO_H

void		gnl_flush(const int fd);
void		gnl_clear(void);

# endif

#endif
