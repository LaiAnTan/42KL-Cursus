#ifndef GNL

# define GNL

#ifndef BUFFER_SIZE

/* BUFFER_SIZE = size of temporary storage area */
# define BUFFER_SIZE 69
#endif

#include <stdlib.h>
#include <fcntl.h>

char	*get_next_line(int fd);
void	*realloc(void *ptr, size_t size);

#endif