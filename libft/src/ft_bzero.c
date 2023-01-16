/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:25:42 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:43:35 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t			idx;
	unsigned char	*dest;

	dest = (unsigned char *) s;
	idx = 0;
	while (idx < n)
	{
		dest[idx++] = 0;
	}
	return (dest);
}

// #include <string.h>
// int main(void)
// {
// 	size_t	len = 5;

// 	unsigned char test[] = "Cheese";
// 	ft_bzero(test, len);
// 	//bzero(test, len);
//     puts("new str = ");
//     for (size_t i = 0; i < sizeof(test); i++)
//         printf("%i ", test[i]);

// 	printf("new str = %s", test);
// 	return (0);
// }