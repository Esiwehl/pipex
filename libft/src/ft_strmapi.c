/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 19:22:32 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:46:04 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	idx;
	size_t	len;
	char	*mapped;

	idx = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	mapped = (char *)malloc(((len + 1) * sizeof(char)));
	if (!mapped)
		return (NULL);
	while (idx < len)
	{
		mapped[idx] = f(idx, s[idx]);
		idx++;
	}
	mapped[idx] = '\0';
	return (mapped);
}

// char upper(unsigned int x, char c)
// {
// 	ft_putchar_fd(c, 1);
// 	write(1, "B\t ", 2);
// 	if (c <= 'z' && c >= 'a')
// 		c -= ('a' - 'A');
// 	ft_putchar_fd(c, 1);
// 	write(1, "\t ", 1);
// 	return (c);
// }

// int main()
// {
// 	char str[] = "ik wil ook kaas.";
// 	char (*ftmp)(unsigned int, char) = &upper;
// 	char *tmp;

// 	tmp = ft_strmapi(str, ftmp);
// 	printf("\nstring is: %s", tmp);
// 	free(tmp);
// }