/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:36:23 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/05 15:51:14 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_max( int *arr, int size)
{
	int		i;
	int		max;
	int		index;

	i = 0;
	max = arr[0];
	index = 0;
	while (i < size)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	rotate_and_push(t_stack *stack)
{
	int		i;
	int		imax;

	i = 0;
	while (stack ->stack_b[0] > stack ->stack_a[i] && i < stack ->size_a)
		i++;
	imax = find_index_max(stack ->stack_a, stack ->size_a);
	if (i < imax)
		while (i--)
			ra(stack);
	else
		while (i++ < stack ->size_a)
			rra(stack);
	pa(stack);
	imax = find_index_max(stack ->stack_a, stack ->size_a);
	while (!check_sort(stack ->stack_a, stack ->size_a))
	{
		if (imax >= stack ->size_a / 2)
			rra(stack);
		else
			ra(stack);
	}
	return ;
}

void	small_sort(t_stack *stack)
{
	while (stack ->size_a > 3)
		pb(stack);
	sort_3(stack);
	while (stack ->size_b > 0)
		rotate_and_push(stack);
	return ;
}
