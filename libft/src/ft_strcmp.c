/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 16:18:25 by ewehl         #+#    #+#                 */
/*   Updated: 2023/01/16 13:33:00 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	idx;

	idx = 0;
	while (s1[idx] && (s1[idx] == s2[idx]))
		idx++;
	return ((unsigned char) s1[idx] - (unsigned char) s2[idx]);
}

// #include <string.h>
// int main()
// {
//     printf("O: %d\n", strncmp("", "", 1));
//     printf("M: %d\n", ft_strncmp("", "", 1));
//     return (0);
// }