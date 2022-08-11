#ifndef LIBFTPRINTF
#define LIBFTPRINTF

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>



//main
int		ft_printf(const char *format, ...);

//flags
typedef struct s_flags
{
	int				signflag;
	int				hashflag;
	int				spaceflag;
}					t_flags;

t_flags	*ft_genflag(void);
void	ft_resetflag(t_flags *flag);

//print functions
void	ft_printchr(char c);
void	ft_printstr(char *s);
void	ft_printptr(uintptr_t n);
void	ft_printdec(int n);
void	ft_printint(int n);
void	ft_printundec(unsigned int n);
void	ft_printhexlow(int n);
void	ft_printhexup(int n);
void	ft_printpercent(void);

//misc functions
char	*ft_itoa(int n);
char	*ft_unitoa(unsigned int n);
size_t	ft_strlen(const char *str);

#endif
