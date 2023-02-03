/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 17:31:38 by ewehl         #+#    #+#                 */
/*   Updated: 2022/10/24 11:04:08 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_me(char **s, int max)
{
	int	idx;

	idx = 0;
	while (s[idx] && idx < max)
	{
		free(s[idx]);
		idx++;
	}
	free(s);
	return (NULL);
}

static int	get_wordc(char const *s, char c)
{
	int	count;
	int	idx;

	idx = 0;
	count = 0;
	while (s[idx] != '\0')
	{
		while (s[idx] && (s[idx] == c))
			idx++;
		if (s[idx])
		{
			count++;
			while (s[idx] && (s[idx] != c))
				idx++;
		}
	}
	return (count);
}

static char	*mallnput_word(char const *s, char c)
{
	char	*word;
	int		idx;

	idx = 0;
	while (s[idx] && (s[idx] != c))
		idx++;
	word = malloc(sizeof(char) * (idx + 1));
	if (!word)
		return (NULL);
	idx = 0;
	while (s[idx] && (s[idx] != c))
	{
		word[idx] = s[idx];
		idx++;
	}
	word[idx] = '\0';
	return (word);
}

static char	**actual_splitncheck(char **dest, char const *s, char c)
{
	int		x;

	x = 0;
	while (*s != '\0')
	{
		while (*s && (*s == c))
			s++;
		if (*s && (*s != c))
		{
			dest[x] = mallnput_word(s, c);
			if (dest[x] == NULL)
				return (free_me(dest, x));
			x++;
			while (*s && (*s != c))
				s++;
		}
	}
	dest[x] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		words;

	words = get_wordc(s, c);
	dest = (char **)malloc(sizeof(char *) * (words + 1));
	if (!dest)
		return (NULL);
	return (actual_splitncheck(dest, s, c));
}

// int main()
// {
// 	char str[] = "Deze\0Zin\0Moet_Worden_Gesplit\0";
// 	char c = '\0';
// 	char **holder;

// 	holder = ft_split(str, c);
// 	for (size_t i = 0; i< 2; i++)
// 		printf("str[%lu] = %s\n", i, holder[i]);
// 	free(holder);
// }
