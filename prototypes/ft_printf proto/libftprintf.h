#ifndef LIBFTPRINTF
#define LIBFTPRINTF

#include <stdarg.h>
#include "libft.h"



//main
int		ft_printf(const char *format, ...);


//functions that print
void	ft_printchr(char c);
void	ft_printstr(char *s);
void	ft_printptr(uintptr_t n);
void	ft_printdec(int n);
void	ft_printint(int n);

//libft func
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);

#endif
