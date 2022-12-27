/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:50:43 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:44:58 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;
	size_t			idx;

	idx = 0;
	t_dst = (unsigned char *) dst;
	t_src = (unsigned char *) src;
	if (!src && !dst)
		return (0);
	while (idx < n)
	{
		t_dst[idx] = t_src[idx];
		idx++;
	}
	return (t_dst);
}

// #include <string.h>
// int	main(void)
// {
// 	// char s1[] = "1234";
// 	// char s2[] = "9876";
// 	int s1[] = {9,8,7,6};
// 	int s2[] = {1,2,3};

// 	puts("before");
// 	for(size_t i = 0; i < (sizeof(s1)/sizeof(int)); i++)
// 	{
// 		printf("s2 = %p\t", s2+i);
// 		printf("at = %d\t", s2[i]);
// 		printf("s1 = %p\t", s1+i);
// 		printf("at = %d\n", s1[i]);
// 	}
// 	memcpy(s2, s1, sizeof(s1));
// 	// ft_memcpy(s2 + 1, s1, (sizeof(s2)));
// 	puts("\nafter");
// 	for(size_t i = 0; i < (sizeof(s1)/sizeof(int)); i++)
// 	{
// 		printf("s2 = %p\t", s2+i);
// 		printf("at = %d\t", s2[i]);
// 		printf("s1 = %p\t", s1+i);
// 		printf("at = %d\n", s1[i]);
// 	}
// }