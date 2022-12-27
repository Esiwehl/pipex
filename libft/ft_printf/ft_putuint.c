/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putuint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 14:23:32 by ewehl         #+#    #+#                 */
/*   Updated: 2022/10/30 20:01:08 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"

char	*ft_uitoa(unsigned int n)
{
	char		*numa;
	size_t		len;

	len = ft_getlen(n, 10);
	numa = (char *)malloc(sizeof(char) * (len + 1));
	if (!numa)
		return (NULL);
	numa[len] = '\0';
	if (n == 0)
		numa[0] = '0';
	while (n)
	{
		len--;
		numa[len] = (n % 10) + '0';
		n /= 10;
	}
	return (numa);
}

size_t	ft_putuint(unsigned int n)
{
	size_t	count;
	char	*num;

	count = 0;
	if (n < 10)
		return (ft_putchar_len(n + '0'));
	num = ft_uitoa(n);
	count += ft_putstr_len(num);
	free(num);
	return (count);
}
