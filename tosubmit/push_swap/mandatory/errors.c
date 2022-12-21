#include "push_swap.h"

int	error(int code, t_stack *stack)
{
	write(STDOUT_FILENO, "Error\n", 6);
	deinitstack(stack);
	exit(code);
	return (0);
}

void	check_duplicate(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack ->size_a)
	{
		j = i + 1;
		while (j < stack ->size_a)
		{
			if (stack ->stack_a[i] == stack ->stack_a[j])
				error(3, stack);
			j++;
		}
		i++;
	}
}