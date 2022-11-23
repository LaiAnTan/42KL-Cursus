#include "checker.h"

static int	push(int fsize, int tsize, int *from, int *to)
{
	int		i;
	int		temp;

	i = 0;
	
	if (!fsize)
		return (-1);
	temp = from[0];
	while (tsize)
	{
		to[tsize] = to[tsize - 1];
		tsize--;
	}
	while (i < fsize - 1)
	{
		from[i] = from[i + 1];
		i++;
	}
	to[0] = temp;
	return (0);
}

void	pa(t_stack *stack)
{
	int	i;

	i = push(stack ->size_b, stack ->size_a, stack ->stack_b, stack ->stack_a);
	if (!i)
	{
		stack ->size_a += 1;
		stack ->size_b -= 1;
		stack ->op_num++;
	}
	return ;
}

void	pb(t_stack *stack)
{
	int	i;

	i = push(stack ->size_a, stack ->size_b, stack ->stack_a, stack ->stack_b);
	if (!i)
	{
		stack ->size_a -= 1;
		stack ->size_b += 1;
		stack ->op_num++;
	}
	return ;
}