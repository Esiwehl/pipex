/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 11:04:38 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:45:27 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		write(fd, &s[idx++], 1);
}

// int main()
// {
//     ft_putstr_fd("Kaas", 2);
// }