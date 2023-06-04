/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:00:19 by tlai-an           #+#    #+#             */
/*   Updated: 2022/08/01 08:00:19 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_iteri(t_list *lst, void (*f) (void *))
{
	t_list *node;
	
	node = lst;
	while (node != NULL)
	{
		f(node -> content);
		node = node -> next;
	}
}