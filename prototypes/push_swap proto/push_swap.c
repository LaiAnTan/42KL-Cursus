#include "push_swap.h"


/* (top of stack) "int arr" (bottom of stack) */

int main(int argc, char *argv[])
{
	t_stack		*stack;
	int			max_size;

	max_size = argc - 1;
	printf("max_size = %d\n", max_size);
	stack = genstack();
	initstack(stack, max_size, argv);
	if (check_duplicate(stack ->stack_a, stack ->size_a) == -1)
		error(3, stack);
	check_sort(stack ->stack_a, stack ->size_a, stack);
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

void	print_stack(int *stack, int size)
{
	int		i;
	
	i = 0;
	while (i < size)
	{
		printf("%d ", stack[i]);
		i++;
	}
	printf("\n");
}

void	check_sort(int *arr, int size, t_stack *stack)
{
	int		i;

	i = 0;
	while (i < (size - 1))
	{
		if (arr[i] > arr[i + 1])
			return ;
		i++;
	}
	deinitstack(stack);
	exit(0);
	return ;
}