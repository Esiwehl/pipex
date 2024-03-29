/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 13:55:01 by ewehl         #+#    #+#                 */
/*   Updated: 2022/10/28 13:55:01 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_getlen(size_t num, size_t base)
{
	size_t	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= base;
	}
	return (len);
}

size_t	ft_puthex(unsigned long n, char format)
{
	size_t	count;
	char	*base;

	count = ft_getlen(n, 16);
	base = NULL;
	if (!n)
		return (ft_putstr_len("0"));
	if (format == 'X')
		base = "0123456789ABCDEF";
	else if (format == 'x')
		base = "0123456789abcdef";
	if (n > 15)
	{
		ft_puthex((n / 16), format);
		ft_putchar_len(base[n % 16]);
	}
	else
		ft_putchar_len(base[n]);
	return (count);
}

size_t	ft_putptr(unsigned long ptr)
{
	size_t	count;

	count = write(1, "0x", 2) + ft_puthex(ptr, 'x');
	return (count);
}
