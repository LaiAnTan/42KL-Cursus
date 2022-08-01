/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:19:10 by tlai-an           #+#    #+#             */
/*   Updated: 2022/08/01 08:19:10 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void *(*del)(void *))
{
	t_list	*node;
	t_list	*newNode;
	t_list	*newlist;

	node = lst;
	while (lst != NULL)
	{
		newNode = ft_lstnew(f(lst -> content));
		node = node -> next;
		ft_lstadd_back(newlist, newNode);
	}
}