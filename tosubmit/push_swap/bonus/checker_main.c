/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:32:58 by tlai-an           #+#    #+#             */
/*   Updated: 2022/12/22 17:32:59 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack		*stack;
	int			max_size;
	char		*op;

	max_size = argc - 1;
	if (!max_size)
		return (0);
	stack = genstack();
	initstack(stack, max_size, argv);
	check_duplicate(stack);
	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		run_operation(stack, op);
		free(op);
	}
	validate_sort(stack);
	deinitstack(stack);
	return (0);
}

int *arg_to_stack(int size, char **argv, t_stack *stack)
{
	int		i;
	int		j;
	int		*arr;

	i = 0;
	j = 1;
	arr = (int *) malloc (sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (size--)
	{
		arr[i] = ft_atoi(argv[j], stack);
		i++;
		j++;
	}
	return (arr);
}

void	validate_sort(t_stack *stack)
{
	int		i;
	int		size;
	int		*arr;

	i = 0;
	size = stack ->size_a;
	arr = stack ->stack_a;
	if (stack ->size_b != 0)
	{
		write(STDOUT_FILENO, "KO\n", 3);
		return ;
	}
	while (i < (size - 1))
	{
		if (arr[i] > arr[i + 1])
		{
			write(STDOUT_FILENO, "KO\n", 3);
			return ;
		}
		i++;
	}
	write(STDOUT_FILENO, "OK\n", 3);
	return ;
}