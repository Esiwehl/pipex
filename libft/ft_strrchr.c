/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:56:04 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:46:18 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while ((int) len >= 0)
	{
		if (s[len] == (unsigned char) c)
			return ((char *) &s[len]);
		len--;
	}
	return (NULL);
}

// #include <string.h>
// int main()
// {
//     char *src = "bonjourno";
//     char *d1 = strrchr(src, '\0');
//     char *d2 = ft_strrchr(src, '\0');
// 		printf("O:: %s\n", d1);
// 		printf("M:: %s\n", d2);
//     return (0);
// }