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
	if(stack ->size_a > 1)
	{
		printf("sa\n");
		swap(stack ->stack_a);
		stack ->op_num++;
	}
	return ;
}

void	sb(t_stack *stack)
{
	if(stack ->size_b > 1)
	{
		printf("sb\n");
		swap(stack ->stack_b);
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
		swap(stack ->stack_a);
		i++;
	}
	if(stack ->size_b > 1)
	{
		swap(stack ->stack_b);
		i++;
	}
	if (i)
	{
		stack ->op_num++;
		printf("ss\n");
	}
	return ;
}
