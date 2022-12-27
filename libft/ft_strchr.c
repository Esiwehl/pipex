/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:56:04 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:45:34 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char) c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

// #include <string.h>
// int main()
// {
//     char test[] = "Ik ben supercool.";
//     int t = 'o' + 256;

//     printf("O: %s\n", strchr(test, t));
//     printf("M: %s\n", ft_strchr(test, t));
//     return (0);
// }