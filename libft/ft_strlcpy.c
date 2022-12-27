/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/09 18:27:24 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:45:54 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	s_len;

	s_len = ft_strlen(src);
	if (s_len + 1 < dsize)
		ft_memcpy(dst, src, s_len + 1);
	else if (dsize != 0)
	{
		ft_memcpy(dst, src, dsize - 1);
		dst[dsize - 1] = '\0';
	}
	return (s_len);
}

// int	main(void)
// {
// 	// char	str1[] = "Test string 1";
// 	// char	str2[] = "String 2 test.";
// 	// char 	dest[] = "Kaas";
// 	// char 	dest2[] = "Ik wil ook kaas.";
// 	// unsigned int 	num = 5;
// 	// unsigned int 	num2 = 16;

// 	// printf("Length of str1 = %u\n", ft_strlcpy(dest, str1, num));
// 	// printf("Dest = %s\n", dest);
// 	// printf("Length of str2 = %u\n", ft_strlcpy(dest2, str2, num2));
// 	printf("cp = %zu ", ft_strlcpy(((void *)0), ((void *)0), 10));
// 	return (0);
// }