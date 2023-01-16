/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:51:12 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:45:04 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;

	t_dst = (unsigned char *) dst;
	t_src = (unsigned char *) src;
	if (!len)
		return (dst);
	if (dst <= src)
		return (ft_memcpy(t_dst, t_src, len));
	while (len--)
		*(t_dst + (len)) = *(t_src + (len));
	return (dst);
}

// #include <string.h>
// int	main(void)
// {
// 	// char s1[] = "1234";
// 	// char s2[] = "9876";
// 	int s1[] = {1,2,3,4};
// 	int s2[] = {9,8,7,6};

// 	puts("before");
// 	for(size_t i = 0; i < (sizeof(s1)/sizeof(int)); i++)
// 	{
// 		printf("s2 = %p\t", s2+i);
// 		printf("at = %d\t", s2[i]);
// 		printf("s1 = %p\t", s1+i);
// 		printf("at = %d\n", s1[i]);
// 	}
// 	// memmove(s2, s1, sizeof(s1));
// 	ft_memmove(s2, s1, (sizeof(s1)));
// 	puts("\nafter");
// 	for(size_t i = 0; i < (sizeof(s1)/sizeof(int)); i++)
// 	{
// 		printf("s2 = %p\t", s2+i);
// 		printf("at = %d\t", s2[i]);
// 		printf("s1 = %p\t", s1+i);
// 		printf("at = %d\n", s1[i]);
// 	}
//     return (0);
// }