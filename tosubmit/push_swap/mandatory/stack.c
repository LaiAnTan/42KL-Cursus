#include "push_swap.h"

t_stack	*genstack(void)
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	resetstack(stack);
	return (stack);
}

void resetstack(t_stack *stack)
{
	stack ->stack_a = 0;
	stack ->stack_b = 0;
	stack ->size_a = 0;
	stack ->size_b = 0;
	stack ->op_num = 0;
	return ;
}

void initstack(t_stack *stack, int max_size, char **argv)
{
	stack ->stack_a = arg_to_stack(max_size, argv, stack);
	stack ->stack_b = (int *) malloc (sizeof(int) * max_size);
	stack ->size_a = max_size;
	stack ->size_b = 0;
	stack ->op_num = 0;
	return ;
}

void	deinitstack(t_stack *stack)
{
	free(stack ->stack_a);
	free(stack ->stack_b);
	free(stack);
	return ;
}
