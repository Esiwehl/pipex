/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 16:38:04 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:44:52 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t_s;
	size_t			idx;

	idx = 0;
	t_s = (unsigned char *) s;
	while (idx < n)
	{
		if (t_s[idx] == (unsigned char) c)
			return ((void *)(s + idx));
		idx++;
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
//     char test[] = "Ik ben supercool.";
//     char t = '\0';
//
//     printf("O: %s\n", memchr(test, t, sizeof(test)));
//     printf("M: %s\n", (unsigned char *)ft_memchr(test, t, sizeof(test)));
//     return (0);
// }