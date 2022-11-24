#include "checker.h"

int		run_operation(t_stack *stack, char *op)
{
	if (ft_strlen(op) > 4)
		error(4, stack);
	if (!ft_strcmp(op, "pa\n"))
		pa(stack);
	else if (!ft_strcmp("pb\n", op))
		pb(stack);
	else if (!ft_strcmp("sa\n", op))
		sa(stack);
	else if (!ft_strcmp("sb\n", op))
		sb(stack);
	else if (!ft_strcmp("ss\n", op))
		ss(stack);
	else if (!ft_strcmp("ra\n", op))
		ra(stack);
	else if (!ft_strcmp("rb\n", op))
		rb(stack);
	else if (!ft_strcmp("rr\n", op))
		rr(stack);
	else if (!ft_strcmp("rra\n", op))
		rra(stack);
	else if (!ft_strcmp("rrb\n", op))
		rrb(stack);
	else if (!ft_strcmp("rrr\n", op))
		rrr(stack);
	else
		error(4, stack);
	return (0);
}