/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strldup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/09 18:26:55 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:45:36 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

char	*ft_strldup(char *s1, size_t len)
{
	char	*dup;

	if (!s1 || (len > ft_strlen(s1)))
		return (NULL);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	dup[len] = '\0';
	while (len--)
		dup[len] = s1[len];
	return (dup);
}
