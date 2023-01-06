/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:47:58 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/05 15:51:19 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack)
{
	int	*a;

	a = stack ->stack_a;
	while (!check_sort(stack ->stack_a, 2))
	{
		if (a[0] > a[1])
			sa(stack);
	}
}

void	sort_3(t_stack *stack)
{
	int	*a;

	a = stack ->stack_a;
	while (!check_sort(stack ->stack_a, 3))
	{
		if (a[1] < a[2] && a[2] < a[0])
			ra(stack);
		else if (a[1] < a[0] && a[2] < a[1])
		{
			sa(stack);
			rra(stack);
		}
		else if (a[2] < a[0] && a[0] < a[1])
			rra(stack);
		else if (a[0] < a[2] && a[1] < a[0])
			sa(stack);
		else if (a[0] < a[2] && a[2] < a[1])
		{
			rra(stack);
			sa(stack);
		}
	}
	return ;
}

void	sort(t_stack *stack)
{
	if (stack ->size_a == 2)
		sort_2(stack);
	else if (stack ->size_a == 3)
		sort_3(stack);
	else if (stack ->size_a < 100)
		small_sort(stack);
	else
		radix_sort(stack);
	return ;
}
