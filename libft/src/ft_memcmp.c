/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 17:32:07 by ewehl         #+#    #+#                 */
/*   Updated: 2023/01/16 13:33:00 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;
	size_t			idx;

	idx = 0;
	if (n == 0)
		return (0);
	cs1 = (unsigned char *) s1;
	cs2 = (unsigned char *) s2;
	while ((cs1[idx] == cs2[idx]) && (idx < n - 1))
		idx++;
	return (cs1[idx] - cs2[idx]);
}

// #include <string.h>
// int main()
// {
//     printf("O: %d\n", memcmp("zyxbcdefgh", "abcdefgxyz", 0));
//     printf("M: %d\n", ft_memcmp("zyxbcdefgh", "abcdefgxyz", 0));
//     return (0);
// }