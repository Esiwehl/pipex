/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:13:43 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:44:05 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
//     printf("O: %i\n", isdigit('A'));
//     printf("M: %i\n", ft_isdigit('A'));
//     return 0;
// }