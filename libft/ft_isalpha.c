/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:14:42 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:43:52 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// #include <stdio.h>
// #include <ctype.h>
// int	main(void)
// {
// 	int test = '9';
// 	printf("O: %i\n", isalpha(test));
// 	printf("M: %i\n", ft_isalpha(test));
// 	return (0);
// }