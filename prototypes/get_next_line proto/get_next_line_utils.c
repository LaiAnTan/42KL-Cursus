#include "get_next_line.h"

void	*ft_realloc(void *ptr, size_t size)
{
	size_t osize;

	
}


/* The realloc() function changes the size of the memory block pointed to by ptr to size bytes. 
The contents will be unchanged in the range from the start of the region up to the minimum of 
the old and new sizes. If the new size is larger than the old size, 
the added memory will not be initialized. */
// if ptr = NULL -> malloc(size)
// if size = NULL -> free(ptr)
