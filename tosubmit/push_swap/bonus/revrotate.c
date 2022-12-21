#include "checker.h"

int	revrotate(int size, int *stack)
{
	if (size <= 1)
		return (-1);
	size--;
	while (size)
	{
		ft_swap(&stack[size], &stack[size - 1]);
		size--;
	}
	return (0);
}

void	rra(t_stack *stack)
{
	if (!(revrotate(stack ->size_a, stack ->stack_a)))
	{
		stack ->op_num++;
	}
	return ;
}

void	rrb(t_stack *stack)
{
	if(!(revrotate(stack ->size_b, stack ->stack_b)))
	{
		stack ->op_num++;
	}
	return ;
}

void	rrr(t_stack *stack)
{
	int	i;

	i = 0;
	i += revrotate(stack ->size_a, stack ->stack_a);
	i += revrotate(stack ->size_b, stack ->stack_b);
	if (!i)
	{
		stack ->op_num++;
	}
	return ;
}