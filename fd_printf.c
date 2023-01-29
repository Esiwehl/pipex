#include "../inc/libft.h"

int	ft_puts_fd(int fd, char *str)
{
	size_t	idx;

	idx = -1;
	if (!str)
		return(ft_puts_fd(fd, "(null)"));
	return(write(fd, str, ft_strlen(str)));
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
			count += ft_putchar_len(fd, format[idx]);
		if (format[idx] == '%' && format[idx + 1] == 's')
			count += ft_puts_fd(fd, va_arg(args, char *));
		idx++;
	}
	va_end(args);
	return (count);
}
