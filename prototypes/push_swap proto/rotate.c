#include "push_swap.h"

static int	rotate(int stacksize, int *stack)
{
	int		temp;
	int		i;
	int		size;

	i = 1;
	if (stacksize <= 1)
		return (-1);
	else
		size = stacksize;
	temp = stack[0];
	while (size--)
	{
		stack[i - 1] = stack [i];
		i++;
	}
	stack[stacksize - 1] = temp;
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