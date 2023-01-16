/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 17:11:04 by ewehl         #+#    #+#                 */
/*   Updated: 2022/12/27 17:44:47 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*cur;
	int		count;

	count = 0;
	cur = lst;
	while (cur != NULL)
	{
		count++;
		cur = cur -> next;
	}
	return (count);
}
