/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:33:09 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/05 00:59:54 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	error(int code, t_stack *stack, char *op, char **temp)
{
	write(STDOUT_FILENO, "Error\n", 6);
	if (op)
		free(op);
	if (temp)
		free_2d_array(temp);
	deinitstack(stack);
	exit(code);
	return (0);
}

void	check_duplicate(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack ->size_a)
	{
		j = i + 1;
		while (j < stack ->size_a)
		{
			if (stack ->stack_a[i] == stack ->stack_a[j])
				error(3, stack, NULL, NULL);
			j++;
		}
		i++;
	}
}
