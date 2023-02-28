/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_me.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 22:13:17 by ewehl         #+#    #+#                 */
/*   Updated: 2023/02/26 22:13:45 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_me(char **s)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		free(s[idx]);
		idx++;
	}
	free(s);
	return (NULL);
}
