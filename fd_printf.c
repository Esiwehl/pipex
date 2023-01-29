#include "../inc/libft.h"

static void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

static void	ft_putstr(int fd, char *str)
{
	size_t	idx;

	idx = -1;
	if (!str)
		ft_putstr(fd, "(null)");
	write(fd, str, ft_strlen(str));
}

void	fd_printf(int fd, char *s, ...)
{
	va_list	ap;
	int		i;

	i = -1;
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			if (s[++i] == 's')
				ft_putstr(fd, va_arg(ap, char *));
		}
		else
			ft_putchar_fd(fd, s[i]);
	}
	va_end(ap);
}
