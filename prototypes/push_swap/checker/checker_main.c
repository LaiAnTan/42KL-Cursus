#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack		*stack;
	int			max_size;
	char		*op;

	max_size = argc - 1;
	if (!max_size)
		return (0);
	stack = genstack();
	initstack(stack, max_size, argv);
	check_duplicate(stack);
	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		run_operation(stack, op);
		free(op);
	}
	validate_sort(stack);
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

void	validate_sort(t_stack *stack)
{
	int		i;
	int		size;
	int		*arr;

	i = 0;
	size = stack ->size_a;
	arr = stack ->stack_a;
	if (stack ->size_b != 0)
	{
		printf("KO\n");
		return ;
	}
	while (i < (size - 1))
	{
		if (arr[i] > arr[i + 1])
		{
			printf("KO\n");
			return ;
		}
		i++;
	}
	printf("OK\n");
	return ;
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