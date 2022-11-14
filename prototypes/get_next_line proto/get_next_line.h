#ifndef GET_NEXT_LINE

# define GET_NEXT_LINE

#  ifndef BUFFER_SIZE

/* BUFFER_SIZE = size of temporary storage area */
#   define BUFFER_SIZE 5
#  endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);

int		check_nl(char *str);
char	*transfer(int fd, char *buffer, char *content);
char	**seperate_nl(char *str);

size_t	ft_strlen(char *str);
char	*ft_append(char *s1, char *s2);
char	*ft_strdup(const char *s);

#endif