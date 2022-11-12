#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

// main
int	*arg_to_stack(int argc, char **argv);

// operations
void	swap(char c, int *stack);
void	push(char c, int fsize, int tsize, int *from, int *to);
void	rotate(char c, int *stack);

// error
int	error(int code, int *arr);
int	check_duplicate(int	*arr, int len);

// utils
int		ft_atoi(const char *s, int *arr);

#endif