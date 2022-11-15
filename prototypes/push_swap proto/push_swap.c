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
	check_duplicate(stack);
	check_sort(stack);
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

void	check_sort(t_stack *stack)
{
	int		i;
	int		size;

	i = 0;
	size = stack ->size_a - 1;
	if (stack ->size_b)
		return ;
	while (i < (size))
	{
		if (stack ->stack_a[i] > stack ->stack_a[i + 1])
			return ;
		i++;
	}
	status_stack(stack);
	printf("op_num: %d\n", stack ->op_num);
	deinitstack(stack);
	exit(0);
	return ;
}

