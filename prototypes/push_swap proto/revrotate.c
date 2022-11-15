#include "push_swap.h"

static int	revrotate(int stacksize, int *stack)
{
	int		temp;
	int		size;

	if (stacksize <= 1)
		return (-1);
	size = stacksize - 1;
	temp = stack[size];
	while (size)
	{
		stack[size] = stack[size - 1];
		size--;
	}
	stack[0] = temp;
	return (0);
}

void	rra(t_stack *stack)
{
	if (!(revrotate(stack ->size_a, stack ->stack_a)))
	{
		printf("rra\n");
		stack ->op_num++;
	}
	return ;
}

void	rrb(t_stack *stack)
{
	if(!(revrotate(stack ->size_b, stack ->stack_b)))
	{
		stack ->op_num++;
		printf("rb\n");
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
		printf("rrr\n");
	}
	return ;
}