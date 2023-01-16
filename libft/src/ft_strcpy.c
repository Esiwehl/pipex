/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strldup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/09 18:26:55 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:45:36 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

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
