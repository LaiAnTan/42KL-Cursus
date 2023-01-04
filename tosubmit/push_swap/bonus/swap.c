/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:35:29 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/04 16:10:50 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack *stack)
{
	if (stack ->size_a > 1)
	{
		ft_swap(&stack ->stack_a[0], &stack ->stack_a[1]);
		stack ->op_num++;
	}
	return ;
}

void	sb(t_stack *stack)
{
	if (stack ->size_b > 1)
	{
		ft_swap(&stack ->stack_b[0], &stack ->stack_b[1]);
		stack ->op_num++;
	}
	return ;
}

void	ss(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack ->size_a > 1)
	{
		ft_swap(&stack ->stack_a[0], &stack ->stack_a[1]);
		i++;
	}
	if (stack ->size_b > 1)
	{
		ft_swap(&stack ->stack_b[0], &stack ->stack_b[1]);
		i++;
	}
	if (i)
	{
		stack ->op_num++;
	}
	return ;
}
