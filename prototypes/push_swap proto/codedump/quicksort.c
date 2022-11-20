#include "push_swap.h"

void	quick_sort(t_stack *stack)
{
	int		i;
	int		j;
	int		size;
	int		*chunk;

	i = 0;
	j = 0;
	size = stack ->size_a;
	chunk = (int *) malloc (sizeof(int) * size);
	while (j++ < 2) //!check_sort(stack, stack ->stack_a, size)
	{
		while (stack ->size_a > 3)
		{
			qs_a(stack, stack ->size_a);
		}
	}
	free(chunk);
}

int	qs_a(t_stack *stack, int len) //len = length of chunk
{
	int		*a;
	int		i;
	int		pivot;
	int		chunksize;

	a = stack ->stack_a;
	i = 0;
	pivot = a[0];
	chunksize = 0;
	if (len <= 3)
	{
		sort_3a(stack);
		return (0);
	}
	while (i < len)
	{
		if (a[0] < pivot)
		{
			pb(stack);
			chunksize++;
		}
		else
		{
			ra(stack);
			i++;
		}
	}
	status_stack(stack);
	return (qs_b(stack, chunksize));
}

int	qs_b(t_stack *stack, int len) // len = length of chunk
{
	int		*b;
	int		i;
	int		pivot;
	int		chunksize;
	int		rbcount;

	b = stack ->stack_a;
	i = 0;
	pivot = b[0];
	chunksize = 0;
	rbcount = 0;
	while (i < len)
	{
		if (b[0] > pivot)
		{
			pa(stack);
			chunksize++;
		}
		else
		{
			rb(stack);
			i++;
			rbcount++;
		}
	}
	while (rbcount--)
		rrb(stack);
	status_stack(stack);
	return (chunksize);
}

int	chunk_manager(t_stack *stack)
{

}



/*
qs_b

- saves no of times rotated
- sorts in descending before pa
- rr back
- return chunk size
*/