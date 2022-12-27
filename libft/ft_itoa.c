/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 11:47:46 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:44:11 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

static int	get_len(int *nb)
{
	int	len;
	int	n;

	len = 1;
	n = *nb;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*numa;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = get_len(&n);
	numa = (char *)malloc(sizeof(char) * (len + 1));
	if (!numa)
		return (NULL);
	numa[len] = '\0';
	if (n < 0)
	{
		n = -n;
		numa[0] = '-';
	}
	if (n == 0)
		numa[0] = '0';
	while (len-- > 0 && n)
	{
		numa[len] = (n % 10) + '0';
		n /= 10;
	}
	return (numa);
}

// int main()
// {
// 	int x = 1000;
// 	char *strx;
// 	strx = ft_itoa(x);
// 	printf("strx = %s\n", strx);
// 	free (strx);
// }