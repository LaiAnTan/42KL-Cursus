/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 22:10:54 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/30 22:10:54 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list *temp;
	t_list *node;
	node = *lst;

	while (node != NULL)
	{
		temp = node;
		node = node -> next;
		ft_lstdelone(temp, del);
	}
	free(*lst);
}



