#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_stack
{
	int			*stack_a;
	int			*stack_b;
	int			size_a;
	int			size_b;
}				t_stack;


// main
int		*arg_to_stack(int size, char **argv, t_stack *stack);
void	print_stack(int *stack, int size);
void	check_sort(int *arr, int size, t_stack *stack);

// stacks
t_stack	*genstack(void);
void	resetstack(t_stack *stack);
void	initstack(t_stack *stack, int max_size, char **argv);
void	deinitstack(t_stack *stack);

// swap
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

// push
void	pa(t_stack *stack);
void	pb(t_stack *stack);

//rotate
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);

//reverse rotate
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

// error
int		error(int code, t_stack *stack);
int		check_duplicate(int	*arr, int len);

// utils
int		ft_atoi(const char *s, t_stack *stack);
void	test_operations(t_stack *stack);

#endif