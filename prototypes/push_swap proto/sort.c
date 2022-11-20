#include "push_swap.h"

void	sort_3a(t_stack *stack)
{
	int *a;

	a = stack ->stack_a;
	while (!check_sort(stack, stack ->stack_a, 3))
	{
		if (stack ->size_a > 2)
		{
			if (a[1] > a[2] && a[1] > a[0])
				rra(stack);
			else if (a[1] < a[2] && a[1] < a[0])
				ra(stack);
		}
		if (a[0] > a[1])
			sa(stack);
	}
}

void	sort_3b(t_stack *stack)
{
	int *b;

	b = stack ->stack_a;
	while (!check_sort(stack, stack ->stack_b, 3))
	{
		if (stack ->size_b > 2)
		{
			if (b[1] < b[2] && b[1] < b[0])
				rrb(stack);
			else if (b[1] > b[2] && b[1] > b[0])
				rb(stack);
		}
		if (b[0] < b[1])
			sb(stack);
	}
}

void	sort(t_stack *stack)
{
	if (stack ->size_a <= 100)
	{
		if (stack ->size_a <= 3)
			sort_3a(stack);
	}
	return ;
}