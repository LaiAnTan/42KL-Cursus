/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:32:52 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/05 00:53:52 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_strlen(t_stack *stack, char *op)
{
	if (ft_strlen(op) > 4)
		error(4, stack, op, NULL);
}

void	run_operation(t_stack *stack, char *op)
{
	check_strlen(stack, op);
	if (!ft_strcmp("pa\n", op))
		pa(stack);
	else if (!ft_strcmp("pb\n", op))
		pb(stack);
	else if (!ft_strcmp("sa\n", op))
		sa(stack);
	else if (!ft_strcmp("sb\n", op))
		sb(stack);
	else if (!ft_strcmp("ss\n", op))
		ss(stack);
	else if (!ft_strcmp("ra\n", op))
		ra(stack);
	else if (!ft_strcmp("rb\n", op))
		rb(stack);
	else if (!ft_strcmp("rr\n", op))
		rr(stack);
	else if (!ft_strcmp("rra\n", op))
		rra(stack);
	else if (!ft_strcmp("rrb\n", op))
		rrb(stack);
	else if (!ft_strcmp("rrr\n", op))
		rrr(stack);
	else
		error(4, stack, op, NULL);
}
