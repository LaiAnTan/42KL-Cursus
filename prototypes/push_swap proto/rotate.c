#include "push_swap.h"

static void	rotate(int stacksize, int *stack)
{
	int		temp;
	int		i;
	int		size;

	i = 1;
	if (stacksize <= 1)
		return ;
	else
		size = stacksize;
	temp = stack[0];
	while (size--)
	{
		stack[i - 1] = stack [i];
		i++;
	}
	stack[stacksize - 1] = temp;
	return ;
}

void	ra(t_stack *stack)
{
	printf("ra\n");
	rotate(stack ->size_a, stack ->stack_a);
	return ;
}

void	rb(t_stack *stack)
{
	printf("ra\n");
	rotate(stack ->size_b, stack ->stack_b);
	return ;
}

void	rr(t_stack *stack)
{
	printf("rr\n");
	rotate(stack ->size_a, stack ->stack_a);
	rotate(stack ->size_b, stack ->stack_b);
	return ;
}