/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/09 17:48:20 by ewehl         #+#    #+#                 */
/*   Updated: 2023/01/16 13:33:00 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	idx;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (size == 0 || d_len >= size)
		return (s_len + size);
	idx = 0;
	while (src[idx] && (idx + d_len + 1 < size))
	{
		dst[d_len + idx] = src[idx];
		idx++;
	}
	dst[d_len + idx] = '\0';
	return (d_len + s_len);
}

// #include <string.h>
// int	main(void)
// {
// 	char	str1[] = "Some cool string.";
// 	char	str2[] = " This is another cool string!";
// 	// int		sizeSmall = 50;	
// 	int		sizeSmall = 12;
// 	int		ret;

// 	char	buff[sizeSmall];

// 	strcpy(buff, str1);
// 	ret = ft_strlcat(buff, str2, sizeSmall);
// 	// ret = strlcat(buff, str2, sizeSmall);

// 	puts(buff);
// 	printf("Value of buff = %d\n", ret);
// 	printf("Strlcat returns: %d\n", ret);
// 	return (0);
// }