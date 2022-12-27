/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/20 18:04:47 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:49:14 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

char	*ft_strldup(char *s1, size_t len)
{
	char	*dup;

	if (!s1 || (len > ft_strlen(s1)))
		return (NULL);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	dup[len] = '\0';
	while (len--)
		dup[len] = s1[len];
	return (dup);
}

size_t	ft_strcpy(char *dest, char *src)
{
	size_t	idx;

	idx = 0;
	while (src[idx])
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (idx);
}

size_t	ft_find_nl(char *buff)
{
	size_t	idx;

	idx = 0;
	while (buff[idx])
	{
		if (buff[idx] == '\n')
			return (idx + 1);
		idx++;
	}
	return (0);
}

void	*ft_bzero(void *s, size_t n)
{
	size_t			idx;
	unsigned char	*dest;

	dest = (unsigned char *) s;
	idx = 0;
	while (idx < n)
		dest[idx++] = 0;
	return (dest);
}
