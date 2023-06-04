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
		printf("ra\n");
		stack ->op_num++;
	}
	return ;
}

void	rb(t_stack *stack)
{
	
	if(!(rotate(stack ->size_b, stack ->stack_b)))
	{
		stack ->op_num++;
		printf("rb\n");
	}
	return ;
}

void	rr(t_stack *stack)
{
	int	i;

	i = 0;
	i += rotate(stack ->size_a, stack ->stack_a);
	i += rotate(stack ->size_b, stack ->stack_b);
	if (!i)
	{
		stack ->op_num++;
		printf("rr\n");
	}
	return ;
}