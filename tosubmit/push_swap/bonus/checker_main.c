/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:32:58 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/05 01:33:36 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack		*stack;
	int			max_size;
	char		*op;

	max_size = get_max_size(argc, argv);
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
		if (ft_strcmp("\n", op))
			run_operation(stack, op);
		else
			break ;
		free(op);
	}
	if (op)
		free(op);
	validate_sort(stack);
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
	int		i;
	int		j;
	int		k;
	int		*arr;
	char	**temp;

	i = 0;
	j = 1;
	k = 0;
	arr = (int *) malloc (sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (k < size)
	{
		if (has_space(argv[j]))
		{
			temp = ft_split(argv[j], ' ');
			while (temp[i] != NULL)
			{
				arr[k] = ft_atoi(temp[i], stack, (char *)arr, temp);
				k++;
				i++;
			}
			free_2d_array(temp);
		}
		else
			arr[k++] = ft_atoi(argv[j], stack, (char *)arr, NULL);
		i = 0;
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
