/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:35:59 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/05 10:40:21 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

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
int		*arg_to_stack(int size, char **argv, t_stack *stack);
int		check_sort(int *arr, int size);

// stacks
t_stack	*genstack(void);
void	resetstack(t_stack *stack);
void	initstack(t_stack *stack, int max_size, char **argv);
void	deinitstack(t_stack *stack);

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

// operation helpers
int		rotate(int size, int *stack);
int		revrotate(int size, int *stack);

//sort
void	sort(t_stack *stack);
void	small_sort(t_stack *stack);
void	radix_sort(t_stack *stack);

// error handling
int		error(int code, t_stack *stack, char *tab, char **arr);

void	check_duplicate(t_stack *stack);

// utils
void	ft_swap(int *a, int *b);
void	free_2d_array(char **arr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

size_t	ft_strlen(char *str);

int		has_space(char *str);
int		countwords(char const *s, char c);
int		get_max_size(int argc, char **argv);
int		ft_atoi(const char *s, t_stack *stack_tofree,
			char *str_tofree, char **arr_tofree);
int		*ft_intarrdup(int *arr, int size);

char	*ft_strdup(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

#endif