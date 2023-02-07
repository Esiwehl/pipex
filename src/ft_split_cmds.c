/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_cmds.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 17:31:38 by ewehl         #+#    #+#                 */
/*   Updated: 2023/02/07 18:07:07 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

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
	int		count;
	int		idx;
	char	*nxt;

	idx = 0;
	count = 0;
	while (s[idx])
	{
		while (s[idx] && (s[idx] == c))
			idx++;
		count++;
		if (s[idx] == 34 || s[idx] == 39)
		{
			nxt = ft_strrchr(&s[idx + 1], s[idx]);
			idx += (nxt - &s[idx] + 1);
			if (idx > (int) ft_strlen(s))
				idx = (int) ft_strlen(s);
		}
		while (s[idx] && (s[idx] != c) && (s[idx] != 34) && (s[idx] != 39))
			idx++;
	}
	return (count);
}

static char	dub_or_single_quote(char to_compare, char original, int *idx)
{
	if (to_compare == 34 || to_compare == 39)
	{
		*idx += 1;
		return (to_compare);
	}
	return (original);
}

/*
	(nxt - &str[idx]) = wordlen, but norm wouldn't let me..
*/
static char	**fill_array(char **dest, char const *str, char c)
{
	char	flag;
	char	*nxt;
	int		jdx;
	int		idx;

	jdx = 0;
	idx = 0;
	while (str[idx])
	{
		while (str[idx] && str[idx] == c)
			idx++;
		flag = dub_or_single_quote(str[idx], c, &idx);
		nxt = ft_strchr(&str[idx], flag);
		if (!nxt)
		{
			dest[jdx++] = ft_substr(&str[idx], 0, ft_strlen(&str[idx]));
			idx = ft_strlen(str);
		}
		else
		{
			dest[jdx++] = ft_substr(&str[idx], 0, (nxt - &str[idx]));
			idx += (nxt - &str[idx]) + 1;
		}
		if (!dest[jdx - 1])
			return (free_me(dest, jdx));
	}
	return (dest[jdx] = NULL, dest);
}

char	**ft_split_cmds(char const *s, char c)
{
	char	**dest;
	int		wc;

	wc = get_wordc(s, c);
	if (wc == -1)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!dest)
		return (NULL);
	return (fill_array(dest, s, c));
}

/*int	main()
{
	char str[] = "awk 'wc -l'";
	char c = ' ';
	char **holder;

	holder = ft_split(str, c);
	if(!holder)
		return (puts("NULL"));
	for (size_t i = 0; holder[i]; i++)
		printf("str[%lu] = %s\n", i, holder[i]);
	free(holder);
}*/
