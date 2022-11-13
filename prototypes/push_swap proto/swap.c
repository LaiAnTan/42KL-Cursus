#include "push_swap.h"

static void	swap(int *stack)
{
	int		temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	return ;
}

void	sa(t_stack *stack)
{
	printf("sa\n");
	swap(stack ->stack_a);
	return ;
}

void	sb(t_stack *stack)
{
	printf("sb\n");
	swap(stack ->stack_b);
	return ;
}

void	ss(t_stack *stack)
{
	printf("ss\n");
	swap(stack ->stack_a);
	swap(stack ->stack_b);
	return ;
}
