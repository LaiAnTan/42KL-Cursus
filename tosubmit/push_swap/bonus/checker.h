/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:33:05 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/05 13:56:41 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>

typedef struct s_stack
{
	int			*stack_a;
	int			*stack_b;
	int			size_a;
	int			size_b;
	int			op_num;
}				t_stack;

// main
void	validate_sort(t_stack *stack);

int		get_max_size(int argc, char **argv);
int		*arg_to_stack(int size, char **argv, t_stack *stack);

// stacks
t_stack	*genstack(void);
void	resetstack(t_stack *stack);
void	initstack(t_stack *stack, int max_size, char **argv);
void	deinitstack(t_stack *stack);

// check
char	*get_operation(t_stack *stack);

void	run_operation(t_stack *stack, char *op);

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
void	check_duplicate(t_stack *stack);

int		error(int code, t_stack *stack, char *op, char **temp);

// utils
void	ft_swap(int *a, int *b);
void	free_2d_array(char **arr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

int		ft_atoi(const char *s, t_stack *stack_tofree,
			char *str_tofree, char **arr_tofree);
int		*ft_intarrdup(int *arr, int size);
int		ft_strcmp(char *s1, char *s2);
int		has_space(char *str);
int		countwords(char const *s, char c);

size_t	ft_strlen(char *str);

char	*ft_append(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

// get_next_line
char	*get_next_line(int fd);
int		check_nl(char *str, int size);
char	*transfer(int fd, char *buffer, char *content);
char	**seperate_nl(char *str);

#endif
