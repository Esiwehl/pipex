/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 21:03:06 by ewehl         #+#    #+#                 */
/*   Updated: 2023/01/29 16:21:24 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "libft.h"

char	*get_next_line(int fd);

char	*get_input(int fd, char *line);
char	*ft_strldup(char *s1, size_t len);
void	*ft_bzero(void *s, size_t n);
char	*ft_strappend(char *dst, char *src);
ssize_t	schmove(char *buff, size_t start);
size_t	ft_strlen(const char *str);
size_t	ft_strcpy(char *dest, char *src);
size_t	ft_find_nl(char *buff);

#endif
