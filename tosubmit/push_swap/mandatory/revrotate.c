/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:36:13 by tlai-an           #+#    #+#             */
/*   Updated: 2022/12/22 17:36:14 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	revrotate(int size, int *stack)
{
	if (size <= 1)
		return (-1);
	size--;
	while (size)
	{
		ft_swap(&stack[size], &stack[size - 1]);
		size--;
	}
	return (0);
}

void	rra(t_stack *stack)
{
	if (!(revrotate(stack ->size_a, stack ->stack_a)))
	{
		write(STDOUT_FILENO, "rra\n", 4);
		stack ->op_num++;
	}
	return ;
}

void	rrb(t_stack *stack)
{
	if(!(revrotate(stack ->size_b, stack ->stack_b)))
	{
		write(STDOUT_FILENO, "rrb\n", 4);
		stack ->op_num++;
	}
	return ;
}

void	rrr(t_stack *stack)
{
	int	i;

	i = 0;
	i += revrotate(stack ->size_a, stack ->stack_a);
	i += revrotate(stack ->size_b, stack ->stack_b);
	if (i != -2)
	{
		write(STDOUT_FILENO, "rrr\n", 4);
		stack ->op_num++;
	}
	return ;
}