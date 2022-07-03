#include "libft.h"

void *ft_calloc(unsigned int nmemb, unsigned int size);

int main(void) 
{
   int n = 10;
   char *a;
   int *b;

   a = (char *) ft_calloc (n, sizeof(char));
   b = (int *) ft_calloc (n , sizeof(int));
   printf("char calloc result: ");
   for(int i = 0 ; i < 10 ; i++)
   {
   		printf("%d ",a[i]);
   }
   printf("\n");
   printf("int calloc result : ");
   for(int i = 0 ; i < 10 ; i++)
   {
   		printf("%d ",b[i]);
   }
   free(a);
   free(b);

   return(0);
}