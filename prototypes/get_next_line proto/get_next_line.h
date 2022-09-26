#ifndef GET_NEXT_LINE

# define GET_NEXT_LINE

#ifndef BUFFER_SIZE

/* BUFFER_SIZE = size of temporary storage area */
# define BUFFER_SIZE 69
#endif

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		check_new_line(char *str);
char	*ft_append(char *src, char *dst);

size_t	ft_strlen(const char *str);

#endif