#include "push_swap.h"

void insertion_sort(int *arr, int size)
{
    int		i;
	int		key;
	int		j;

	i = 1;
   	while (i < size)
	{
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
		{
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
		i++;
    }
}

void	simplify_a(t_stack *stack)
{
	int		i;
	int		j;
	int		size;
	int		*copy;

	i = 0;
	j = 0;
	size = stack ->size_a;
	copy = ft_intarrdup(stack ->stack_a, size);
	insertion_sort(copy, size);
	for (int i = 0; i < size; i++)
		printf("%d ", copy[i]);
	while (i < size)
	{
		while (j < size)
		{
			if (stack ->stack_a[i] == copy[j])
			{
				stack ->stack_a[i] = j;
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	free(copy);
}

int	max_binary_shift(int *arr, int size)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	printf("size = %d\n", size);
	while (i < size)
	{
		if (num < arr[i])
			num = arr[i];
		i++;
	}
	i = 0;
	while (num)
	{
		num = num / 10;
		i++;
	}
	return (i * 4);
}

void	radix_sort(t_stack *stack)
{
	int		i;
	int		size;
	int		lsb;
	int		shift;

	i = 0;
	shift = 0;
	size = stack ->size_a;
	status_stack(stack);
	simplify_a(stack);
	status_stack(stack);
	while (!check_sort(stack, stack ->stack_a, size))
	{
		while (i < size)
		{
			lsb = stack ->stack_a[0];
			lsb = (lsb >> shift) & 1;
			if (lsb == 0)
				pb(stack);
			else if (lsb == 1)
				ra(stack);
			i++;
		}
		i = 0;
		while (stack ->size_b > 0)
			pa(stack);
		shift++;
	}
}