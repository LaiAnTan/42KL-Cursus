#include "push_swap.h"

int	error(int code, t_stack *stack)
{
	if (code == 1)
		printf("Error, Arguement not an integer\n");
	else if (code == 2)
		printf("Error, Arguement overflow\n");
	else if (code == 3)
		printf("Error, Duplicate arguements found\n");
	deinitstack(stack);
	exit(code);
	return (0);
}

int	check_duplicate(t_stack *stack)
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
			{
				j++;
				continue ;
			}
			if (stack ->stack_a[i] == stack ->stack_a[j])
				return (error(3, stack));
			j++;
		}
		i++;
	}
	return (0);
}