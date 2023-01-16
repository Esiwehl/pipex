/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:37:30 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:46:43 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= ('a' - 'A');
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>
// int	main(void)
// {
// 	int test = 'z';
// 	printf("O: %c\n", toupper(test));
// 	printf("M: %c\n", ft_toupper(test));
// 	return (0);
// }