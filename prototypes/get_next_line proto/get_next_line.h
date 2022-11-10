#ifndef GET_NEXT_LINE

# define GET_NEXT_LINE

#ifndef BUFFER_SIZE

/* BUFFER_SIZE = size of temporary storage area */
# define BUFFER_SIZE 2000
#endif

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		check_nl(char *str);
char	**seperate_nl(char *str);

char	*ft_append(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strdup(const char *s);

#endif