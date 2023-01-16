/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/09 19:27:32 by ewehl         #+#    #+#                 */
/*   Updated: 2023/01/16 13:33:00 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	idx;
	char	*strj;

	idx = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strj = (char *)malloc(s1_len + s2_len + 1);
	if (!strj)
		return (NULL);
	while (s1[idx])
	{
		strj[idx] = s1[idx];
		idx++;
	}
	idx = 0;
	while (s2[idx])
	{
		strj[s1_len + idx] = s2[idx];
		idx++;
	}
	strj[s1_len + s2_len] = '\0';
	return (strj);
}

// int main()
// {
//     char s1[] = "Dit is een moker lange string..";
// 	char s2[] = " Dit niet.";
//     char *new;

//     new = ft_strjoin(s1, s2);
//		if (new)
//     		size_t len = ft_strlen(new);
//     printf("See if this works:: %s\n", new);
//     if (new)
//     		printf("len = %lu", len);
//     free(new);
// }