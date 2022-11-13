#include "push_swap.h"

static void revrotate(int stacksize, int *stack)
{
	int		temp;
	int		size;

	if (stacksize <= 1)
		return ;
	size = stacksize - 1;
	temp = stack[size];
	while (size)
	{
		stack[size] = stack[size - 1];
		size--;
	}
	stack[0] = temp;
	return ;
}

void	rra(t_stack *stack)
{
	printf("rra\n");
	revrotate(stack ->size_a, stack ->stack_a);
	return ;
}

void	rrb(t_stack *stack)
{
	printf("rrb\n");
	revrotate(stack ->size_b, stack ->stack_b);
	return ;
}

void	rrr(t_stack *stack)
{
	printf("rrr\n");
	revrotate(stack ->size_a, stack ->stack_a);
	revrotate(stack ->size_b, stack ->stack_b);
	return ;
}