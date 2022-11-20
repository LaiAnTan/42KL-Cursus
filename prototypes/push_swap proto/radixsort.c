#include "push_swap.h"

int	max_binary_shift(int *arr, int size)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (i < size)
	{
		if (num < arr[i])
			num = arr[i];
		else if (num >= arr[i])
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
	int		bit;
	int		shift;
	int		max_binary_digit;

	i = 0;
	shift = 0;
	max_binary_digit = max_binary_shift(stack ->stack_a, stack ->size_a);
	size = stack ->size_a;
	while (shift <= max_binary_digit)
	{
		while (i < size - 1)
		{
			bit = stack ->stack_a[0];
			// printf("current: %d shift by %d\n", bit, shift);
			bit = (bit >> shift) & 1;
			if (bit == 0)
			{
				if (stack ->size_a == 0)
					break ;
				pb(stack);
			}
			else if (bit == 1)
				ra(stack);
			i++;
		}
		i = 0;
		while (stack ->size_b > 0)
			pa(stack);
		shift++;
	}
}