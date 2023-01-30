/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fd_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 00:58:41 by ewehl         #+#    #+#                 */
/*   Updated: 2023/01/30 02:54:46 by ewehl         ########   odam.nl         */
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
		idx++;
	}
	va_end(args);
	return (count);
}
