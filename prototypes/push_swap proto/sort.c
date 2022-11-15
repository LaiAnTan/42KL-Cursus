#include "push_swap.h"

void	smallest_sort(t_stack *stack)
{
	int *a;

	a = stack ->stack_a;
	while (1)
	{
		check_sort(stack);
		if (a[0] > a[1])
			sa(stack);
		else
			ra(stack);
	}
}

void	insertion_sort(t_stack *stack) //garbage
{
	int		i;
	int		size;
	int		*a;
	int		*b;

	i = 0;
	size = stack ->size_a;
	a = stack ->stack_a;
	b = stack ->stack_b;
	while (1)
	{
		check_sort(stack);
		if (a[0] < a[1])
			rra(stack);
		else
		{
			pb(stack);
			while (i < size)
			{
				if (a[0] > b[0])
				{
					pa(stack);
					i = 0;
					break ;
				}
				else if (a[0] < b[0])
				{
					rra(stack);
					i++;
				}
			}
			i = 0;
			pa(stack);
			rra(stack);
		}
	}
	return ;
}

void	sort(t_stack *stack)
{
	if (stack ->size_a <= 3)
		smallest_sort(stack);
	insertion_sort(stack);
	return ;
}