/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:33:00 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:46:00 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

// #include <string.h>
// int main(void)
// {
//     char test[] = "uhfuafeiiudifanaejicenjeoe ijoafan";

//     printf("O = %lu\n", strlen(test));
//     printf("M = %lu\n", ft_strlen(test));

//     return (0);
// }