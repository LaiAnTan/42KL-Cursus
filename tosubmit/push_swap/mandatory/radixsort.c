/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:36:08 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/05 14:10:38 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insertion_sort(int *arr, int size)
{
	int	i;
	int	key;
	int	j;

	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		i++;
	}
}

static void	simplify_a(t_stack *stack)
{
	int		i;
	int		j;
	int		size;
	int		*copy;

	i = 0;
	j = 0;
	size = stack ->size_a;
	copy = ft_intarrdup(stack ->stack_a, size);
	insertion_sort(copy, size);
	while (i < size)
	{
		while (j < size)
		{
			if (stack ->stack_a[i] == copy[j])
			{
				stack ->stack_a[i] = j;
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	free(copy);
}

static void	push_all_b_to_a(t_stack *stack)
{
	while (stack ->size_b > 0)
		pa(stack);
}

void	radix_sort(t_stack *stack)
{
	int		i;
	int		size;
	int		lsb;
	int		shift;

	i = 0;
	shift = 0;
	size = stack ->size_a;
	simplify_a(stack);
	while (!check_sort(stack ->stack_a, size))
	{
		while (i < size)
		{
			lsb = stack ->stack_a[0];
			lsb = (lsb >> shift) & 1;
			if (lsb == 0)
				pb(stack);
			else if (lsb == 1)
				ra(stack);
			i++;
		}
		i = 0;
		push_all_b_to_a(stack);
		shift++;
	}
}
