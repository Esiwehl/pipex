/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lssplit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 06:32:08 by ewehl         #+#    #+#                 */
/*   Updated: 2023/01/30 06:45:08 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int obj_count(char *str, char c)
{
	t_split split;

	split.idx = 0;
	split.jdx = 0;

	while (str[split.idx] && str[split.idx] == c)
		split.idx++;
	while (str[split.idx])
	{
		if (str[split.idx] == '\''|| str[split.idx] == '\"')
			split.
	}
}