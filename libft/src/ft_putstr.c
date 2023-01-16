/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 13:54:49 by ewehl         #+#    #+#                 */
/*   Updated: 2023/01/16 13:34:10 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar_len(int c)
{
	return (write(1, &c, 1));
}

size_t	ft_putstr_len(char *str)
{
	size_t	idx;

	idx = 0;
	if (!str)
		return (ft_putstr_len("(null)"));
	return (write(1, str, ft_strlen(str)));
}

size_t	ft_putnbr_len(int n)
{
	size_t	count;
	char	*num;

	num = ft_itoa(n);
	count = ft_putstr_len(num);
	free(num);
	return (count);
}
