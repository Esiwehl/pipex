/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/09 18:26:55 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:45:36 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

char	*ft_strdup(const char *s)
{
	char	*nstr;
	int		idx;
	int		len;

	idx = 0;
	len = (int)ft_strlen(s);
	nstr = (char *)malloc((len + 1) * sizeof(char));
	if (!nstr)
		return (NULL);
	while (s[idx] != '\0')
	{
		nstr[idx] = s[idx];
		idx++;
	}
	nstr[idx] = '\0';
	return (nstr);
}

// int main()
// {
//     char s1[] = "Dit werkt gwn maat";
//     char *ns1;

//     ns1 = ft_strdup(s1);
//     printf("after ns1 = %s\t", ns1);
//     printf("address = %p\n", ns1);
//     printf("address s1 = %p\n", s1);
//     free(ns1);
//     return 0;
// }