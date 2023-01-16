/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:16:43 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:44:00 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

int	ft_isascii(int c)
{
	return ((c >= 0) && (c <= 127));
}

// #include <ctype.h>
// #include <stdio.h>
// int main(void)
// {
//     int test = 0140;

//     printf("O: %i\n", isascii(test));
//     printf("M: %i\n", ft_isascii(test));
//     return (0);
// }