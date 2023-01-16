/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 18:02:30 by ewehl         #+#    #+#                 */
/*   Updated: 2023/01/16 13:33:00 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	n_len;
	int	idx;

	idx = 0;
	n_len = ft_strlen(needle);
	if ((int) len < 0)
		len = ft_strlen(haystack);
	if (needle[idx] == '\0')
		return ((char *)haystack);
	if (!(int)len || (int)ft_strlen(haystack) < n_len)
		return (NULL);
	while (idx <= ((int)len - n_len) && *haystack)
	{
		if (haystack[idx] == needle[0])
			if (ft_strncmp(haystack + idx, needle, n_len) == 0)
				return ((char *)(haystack + idx));
		idx++;
	}
	return (NULL);
}

// #include <string.h>
// int main()
// {
//     char bigOne[] = "thequickbrownfoxjumpedoverthelazydog";
//     char smallOne[] = "foxj";

//     printf("O: %s\n", strnstr(bigOne, smallOne, -1));
//     printf("M: %s\n", ft_strnstr(bigOne, smallOne, -1));
//     // printf("O: %s\n", strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE",
// 	//						ft_strlen("MZIRIBMZE")));
//     // printf("M: %s\n", ft_strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE",
// 	//						ft_strlen("MZIRIBMZE")));
// }