#include "checker.h"

void	sa(t_stack *stack)
{
	if(stack ->size_a > 1)
	{
		ft_swap(&stack ->stack_a[0], &stack ->stack_a[1]);
		stack ->op_num++;
	}
	return ;
}

void	sb(t_stack *stack)
{
	if(stack ->size_b > 1)
	{
		ft_swap(&stack ->stack_b[0], &stack ->stack_b[1]);
		stack ->op_num++;
	}
	return ;
}

void	ss(t_stack *stack)
{
	int	i;

	i = 0;
	if(stack ->size_a > 1)
	{
		ft_swap(&stack ->stack_a[0], &stack ->stack_a[1]);
		i++;
	}
	if(stack ->size_b > 1)
	{
		ft_swap(&stack ->stack_b[0], &stack ->stack_b[1]);
		i++;
	}
	if (i)
	{
		stack ->op_num++;
	}
	return ;
}
