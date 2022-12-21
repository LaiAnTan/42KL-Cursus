#include "push_swap.h"


/* (top of stack) "int arr" (bottom of stack) */

int main(int argc, char *argv[])
{
	t_stack		*stack;
	int			max_size;

	max_size = argc - 1;
	if (!max_size)
		return (0);
	stack = genstack();
	initstack(stack, max_size, argv);
	check_duplicate(stack);
	if (check_sort(stack ->stack_a, stack ->size_a))
	{
		deinitstack(stack);
		return (0);
	}
	sort(stack);
	deinitstack(stack);
	return (0);
}

int *arg_to_stack(int size, char **argv, t_stack *stack)
{
	int		i;
	int		j;
	int		*arr;

	i = 0;
	j = 1;
	arr = (int *) malloc (sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (size--)
	{
		arr[i] = ft_atoi(argv[j], stack);
		i++;
		j++;
	}
	return (arr);
}

int	check_sort(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

