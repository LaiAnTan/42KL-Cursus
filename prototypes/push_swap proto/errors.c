#include "push_swap.h"

int	error(int code, t_stack *stack)
{
	printf("Error\n");
	deinitstack(stack);
	exit(code);
	return (0);
}

void	check_duplicate(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack ->size_a)
	{
		while (j < stack ->size_a)
		{
			if (i == j)
				j++;
			if (stack ->stack_a[i] == stack ->stack_a[j])
			{
				error(3, stack);
				return ;
			}
			else
				j++;
		}
		i++;
	}
	return ;
}

// duplicates in the middle are not found