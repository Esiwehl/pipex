/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:56:07 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:43:27 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str)
{
	int	idx;
	int	sign;
	int	num;

	idx = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(str[idx]))
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign *= -1;
		idx++;
	}
	while (ft_isdigit(str[idx]))
		num = num * 10 + (str[idx++] - '0');
	return (num * sign);
}

// #include <stdlib.h>
// #include <stdio.h>
// int main(void)
// {
//     char test[] = "++1234";

//     printf("O: %i\n", atoi(test));
//     printf("M: %i\n", ft_atoi(test));
//     return(0);
//     //mogen lamba's nu wel?
// }