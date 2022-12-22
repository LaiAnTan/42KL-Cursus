/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:36:32 by tlai-an           #+#    #+#             */
/*   Updated: 2022/12/22 17:36:33 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	if(stack ->size_a > 1)
	{
		write(STDOUT_FILENO, "sa\n", 3);
		ft_swap(&stack ->stack_a[0], &stack ->stack_a[1]);
		stack ->op_num++;
	}
	return ;
}

void	sb(t_stack *stack)
{
	if(stack ->size_b > 1)
	{
		write(STDOUT_FILENO, "sb\n", 3);
		ft_swap(&stack ->stack_b[0], &stack ->stack_b[1]);
		stack ->op_num++;
	}
	return ;
}

void	ss(t_stack *stack)
{
	int	i;

	i = 0;
	if(stack ->size_a > 1)
	{
		ft_swap(&stack ->stack_a[0], &stack ->stack_a[1]);
		i++;
	}
	if(stack ->size_b > 1)
	{
		ft_swap(&stack ->stack_b[0], &stack ->stack_b[1]);
		i++;
	}
	if (i)
	{
		write(STDOUT_FILENO, "ss\n", 3);
		stack ->op_num++;
	}
	return ;
}
