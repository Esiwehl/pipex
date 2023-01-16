/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:41:51 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:46:22 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int		start;
	unsigned int		end;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	end = ft_strlen((s1 + start));
	while (ft_strchr(set, (s1 + start)[end]) && end != 0)
		end--;
	return (ft_substr(s1, start, end + 1));
}

// int	main()
// {
// 	char *trimmed;
// 	char *trimmed2;

// 	trimmed = ft_strtrim("xxxz  test with x and z and x . zx  xx z", "z x");
// 	write(1,"\n", 1);
// 	trimmed2 = ft_strtrim2("xxxz  test with x and z and x . zx  xx z", "z x");
// 	printf("Mstr = %s\n", trimmed);
// 	printf("Ostr = %s\n", trimmed2);
// 	free(trimmed);
// 	free(trimmed2);
// }

/*(s1 + start)[end]) because {end} is calculated from that same offset.*/