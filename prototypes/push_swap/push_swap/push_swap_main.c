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
	if (check_sort(stack, stack ->stack_a, stack ->size_a))
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

void	print_stack(char c, t_stack *stack)
{
	int		i;
	int		size;
	int		*arr;
	
	i = 0;
	if (c == 'a')
	{
		size = stack ->size_a;
		arr = stack ->stack_a;
	}
	else if (c == 'b')
	{
		size = stack ->size_b;
		arr = stack ->stack_b;
	}
	else
		return ;
	printf("stack %c: ", c);
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

int	check_sort(t_stack *stack, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	// printf("op_num: %d\n", stack ->op_num);
	return (1);
}

