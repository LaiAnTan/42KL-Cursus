/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:35:54 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/05 10:46:52 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* (top of stack) "int arr" (bottom of stack) */

int	main(int argc, char *argv[])
{
	t_stack		*stack;
	int			max_size;

	max_size = get_max_size(argc, argv);
	if (!max_size)
		return (0);
	stack = genstack();
	initstack(stack, max_size, argv);
	check_duplicate(stack);
	if (check_sort(stack ->stack_a, stack ->size_a))
	{
		deinitstack(stack);
		return (0);
	}
	sort(stack);
	deinitstack(stack);
	return (0);
}

int	get_max_size(int argc, char **argv)
{
	int	i;
	int	ms;

	i = 0;
	ms = 0;
	while (i < argc)
	{
		if (has_space(argv[i]))
			ms += countwords(argv[i], ' ');
		else
			ms++;
		i++;
	}
	return (ms - 1);
}

int	*arg_to_stack(int size, char **argv, t_stack *stack)
{
	int		iter[3];
	int		*arr;
	char	**temp;

	iter[0] = 0;
	iter[1] = 1;
	iter[2] = 0;
	arr = (int *) malloc (sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (iter[2] < size)
	{
		if (has_space(argv[iter[1]]))
		{
			temp = ft_split(argv[iter[1]++], ' ');
			while (temp[iter[0]] != NULL)
				arr[iter[2]++] = ft_atoi(temp[iter[0]++], stack,
						(char *)arr, temp);
			free_2d_array(temp);
		}
		else
			arr[iter[2]++] = ft_atoi(argv[iter[1]++], stack, (char *)arr, NULL);
		iter[0] = 0;
	}
	return (arr);
}

int	check_sort(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
