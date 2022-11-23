#ifndef CHECKER_H

# define CHECKER_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

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
void	validate_sort(t_stack *stack);
void	print_stack(char c, t_stack *stack);

// stacks
t_stack	*genstack(void);
void	resetstack(t_stack *stack);
void	initstack(t_stack *stack, int max_size, char **argv);
void	deinitstack(t_stack *stack);
void	status_stack(t_stack *stack);

// check
char	*get_operation(t_stack *stack);
int		run_operation(t_stack *stack, char *op);

// operations
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

// error
int		error(int code, t_stack *stack);
void	check_duplicate(t_stack *stack);

// utils
void	ft_swap(int *a, int *b);
int		ft_atoi(const char *s, t_stack *stack);
int		*ft_intarrdup(int *arr, int size);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_append(char *s1, char *s2);
char	*ft_strdup(char *str);

// get_next_line
char	*get_next_line(int fd);
int		check_nl(char *str, int size);
char	*transfer(int fd, char *buffer, char *content);
char	**seperate_nl(char *str);

#endif

