/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 17:10:57 by ewehl         #+#    #+#                 */
/*   Updated: 2023/02/01 18:51:04 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*t_ptr;
	t_list	*nw_node;

	nw_node = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		t_ptr = f(lst -> content);
		tmp = ft_lstnew(t_ptr);
		if (!tmp)
		{
			free(t_ptr);
			ft_lstclear(&nw_node, del);
			return (NULL);
		}
		ft_lstadd_back(&nw_node, tmp);
		lst = lst -> next;
	}
	return (nw_node);
}
