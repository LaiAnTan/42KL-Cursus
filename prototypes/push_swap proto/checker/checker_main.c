#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack		*stack;
	int			max_size;

	max_size = argc - 1;
	stack = genstack();
	initstack(stack, max_size, argv);
	check_duplicate(stack);
	if (check_sort(stack, stack ->stack_a, stack ->size_a))
	{
		deinitstack(stack);
		return (0);
	}
	deinitstack(stack);
	return (0);
}