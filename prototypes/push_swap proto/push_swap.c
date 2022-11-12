#include "push_swap.h"


/* (top of stack) "int arr" (bottom of stack) */

int main(int argc, char *argv[])
{
	int		*stack_a;
	// int		*stack_b;

	stack_a = arg_to_stack(argc, argv);
	// stack_b = (int *) malloc (sizeof(int) * (argc - 1));
	for(int i = 0; i < argc - 1; i++)
		printf("%d ", stack_a[i]);
	if (check_duplicate(stack_a, (argc - 1)) == -1)
		error(3, stack_a);
	swap('a', stack_a);
	for(int i = 0; i < argc - 1; i++)
		printf("%d ", stack_a[i]);
}

int	*arg_to_stack(int argc, char **argv)
{
	int		i;
	int		*stack;

	i = 0;
	stack = (int *) malloc (sizeof(int) * argc);
	if (!stack)
		return (NULL);
	argv++;
	while (argc - 1)
	{
		stack[i++] = ft_atoi(*argv, stack);
		argv++;
		argc--;
	}
	return (stack);
}