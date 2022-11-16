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
	int			op_num;
}				t_stack;


// main
int		*arg_to_stack(int size, char **argv, t_stack *stack);
void	print_stack(char c, t_stack *stack);
void	check_sort(t_stack *stack);

// stacks
t_stack	*genstack(void);
void	resetstack(t_stack *stack);
void	initstack(t_stack *stack, int max_size, char **argv);
void	deinitstack(t_stack *stack);
void	status_stack(t_stack *stack);

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

//sort
void	sort(t_stack *stack);

// error
int		error(int code, t_stack *stack);
int		check_duplicate(t_stack *stack);

// utils
int		ft_atoi(const char *s, t_stack *stack);
void	test_operations(t_stack *stack);

#endif