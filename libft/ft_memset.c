/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:45:13 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:45:07 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			idx;
	unsigned char	*dest;

	dest = (unsigned char *) b;
	idx = 0;
	while (idx < len)
		dest[idx++] = c;
	return (dest);
}

// #include <string.h>
// int main(void)
// {
// 	unsigned char	*str;
// 	size_t	len = 5;
// 	int	c = 42;

// 	char test[] = "Cheese";
// 	// str = ft_memset(test, c, len);
// 	str = memset(test, c, len);
// 	printf("new str = %s", str);
// 	return (0);
// }
// //why didn't decrementing len work?
// //Should I protect it from empty strings?
// //Should return b or dest?