/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fd_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 00:58:41 by ewehl         #+#    #+#                 */
/*   Updated: 2023/02/18 20:40:03 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_putc_fd(int fd, char c)
{
	return (write(fd, &c, 1));
}

static int	ft_puts_fd(int fd, char *str)
{
	if (!str)
		return (ft_puts_fd(fd, "(null)"));
	return (write(fd, str, ft_strlen(str)));
}

static int	ft_putnum_fd(int fd, int num)
{
	char *num_str;
	int count;

	num_str = ft_itoa(num);
	count = ft_puts_fd(fd, num_str);
	free(num_str);
	return (count);
}

int	fd_printf(int fd, const char *format, ...)
{
	int			idx;
	size_t		count;
	va_list		args;

	idx = 0;
	count = 0;
	va_start(args, format);
	while (format[idx])
	{
		if (format[idx] != '%')
			count += ft_putc_fd(fd, format[idx]);
		if (format[idx] == '%' && format[++idx] == 's')
			count += ft_puts_fd(fd, va_arg(args, char *));
		else if (format[idx] == 'c' && format[idx - 1] == '%')
			count += ft_putc_fd(fd, va_arg(args, int));
		else if (format[idx] == 'd' && format[idx - 1] == '%')
			count += ft_putnum_fd(fd, va_arg(args, int));
		idx++;
	}
	va_end(args);
	return (count);
}

// int	ft_error()
// {
	// 
// }