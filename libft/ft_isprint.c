/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:25:07 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:44:09 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

int	ft_isprint(int c)
{
	return ((c >= 32) && (c <= 126));
}

// #include <ctype.h>
// #include <stdio.h>
// int main(void)
// {
//     int test = 177;

//     printf("O: %i\n", isprint(test));
//     printf("M: %i\n", ft_isprint(test));
//     return (0);
// }