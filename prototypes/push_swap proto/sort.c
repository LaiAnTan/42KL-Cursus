#include "push_swap.h"

void	sort_3(t_stack *stack)
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
	return ;
}

void	small_sort(t_stack *stack)
{
	int		rcount;
	int		*a;
	int		*b;

	rcount = 0;
	sort_3(stack);
	// while (stack ->size_a > 3)
	// 	pb(stack);
	
	status_stack(stack);
	// while (!check_sort(stack , stack ->stack_a, stack ->size_a))
	// 	ra(stack);
}

void	sort(t_stack *stack)
{
	if (stack ->size_a <= 5)
		small_sort(stack);
	else
		radix_sort(stack);
	return ;
}