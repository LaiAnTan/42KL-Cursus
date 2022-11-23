#ifndef CHECKER_H

# define CHECKER_H

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

// stacks
t_stack	*genstack(void);
void	resetstack(t_stack *stack);
void	initstack(t_stack *stack, int max_size, char **argv);
void	deinitstack(t_stack *stack);

// error
int		error(int code, t_stack *stack);
void	check_duplicate(t_stack *stack);

// utils
void	ft_swap(int *a, int *b);
int		ft_atoi(const char *s, t_stack *stack);
int		*ft_intarrdup(int *arr, int size);

#endif

