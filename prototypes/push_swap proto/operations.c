#include "push_swap.h"

void	swap(char c, int *stack)
{
	int		temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	printf("s%c\n", c);
}

void	push(char c, int fsize, int tsize, int *from, int *to)
{
	int		i;

	i = 0;
	if (from == NULL)
		return ;
	while (tsize)
	{
		to[tsize + 1] = to[tsize];
		tsize--;
	}
	to[0] = from[0];
	while (i < fsize)
	{
		from[i + 1] = from[i];
		i++;
 	}
	printf("p%c\n", c);
}

void	rotate(char c, int *stack);