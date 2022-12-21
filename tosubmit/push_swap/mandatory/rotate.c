#include "push_swap.h"

int	rotate(int size, int *stack)
{
	int		i;

	i = 0;
	if (size <= 1)
		return (-1);
	while (i < size - 1)
	{
		ft_swap(&stack[i], &stack[i + 1]);
		i++;
	}
	return (0);
}

void	ra(t_stack *stack)
{
	if (!(rotate(stack ->size_a, stack ->stack_a)))
	{
		write(STDOUT_FILENO, "ra\n", 3);
		stack ->op_num++;
	}
	return ;
}

void	rb(t_stack *stack)
{
	
	if(!(rotate(stack ->size_b, stack ->stack_b)))
	{
		write(STDOUT_FILENO, "rb\n", 3);
		stack ->op_num++;
	}
	return ;
}

void	rr(t_stack *stack)
{
	int	i;

	i = 0;
	i += rotate(stack ->size_a, stack ->stack_a);
	i += rotate(stack ->size_b, stack ->stack_b);
	if (i != -2)
	{
		write(STDOUT_FILENO, "rr\n", 3);
		stack ->op_num++;
	}
	return ;
}