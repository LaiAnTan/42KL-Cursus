/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:35:51 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/04 16:09:57 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(int code, t_stack *stack)
{
	write(STDOUT_FILENO, "Error\n", 6);
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
				error(3, stack);
			j++;
		}
		i++;
	}
}
