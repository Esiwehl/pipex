/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 17:31:38 by ewehl         #+#    #+#                 */
/*   Updated: 2023/01/22 20:33:15 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_delim(char s, char c)
{
	return (s == c);
}

static int	get_idxcount(char const *s, char c)
{
	int	count;
	int	idx;

	idx = 0;
	count = 0;
	while (s[idx] != '\0')
	{
		while (s[idx] && is_delim(s[idx], c))
			idx++;
		if (s[idx] && !is_delim(s[idx], c))
		{
			count++;
			while (s[idx] && !is_delim(s[idx], c))
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
	while (s[idx] && !is_delim(s[idx], c))
		idx++;
	word = malloc(sizeof(char) * (idx + 1));
	if (!word)
		return (NULL);
	idx = 0;
	while (s[idx] && !is_delim(s[idx], c))
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
		while (*s && is_delim(*s, c))
			s++;
		if (*s && !is_delim(*s, c))
		{
			dest[x] = mallnput_word(s, c);
			if (dest[x] == NULL)
			{
				while (x--)
					free(dest[x]);
				free(dest);
				return (NULL);
			}
			x++;
			while (*s && !is_delim(*s, c))
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

	words = get_idxcount(s, c);
	dest = (char **)malloc(sizeof(char *) * (words + 1));
	if (!dest)
		return (NULL);
	return (actual_splitncheck(dest, s, c));
}

// int main()
// {
// 	char str[] = "__Deze_Zin___Moet_Worden_Gesplit";
// 	char c = '_';
// 	char **holder;

// 	holder = ft_split(str, c);
// 	for (size_t i = 0; i< 5; i++)
// 		printf("str[%lu] = %s\n", i, holder[i]);
// 	free(holder);
// }
// get no. of words
// get allocate mem for substr
// put in split arr.