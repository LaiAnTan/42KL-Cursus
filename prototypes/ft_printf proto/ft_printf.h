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
	char			type;
}					t_flags;

t_flags	*ft_genflag(void);
void	ft_resetflag(t_flags *flag);

//print functions
int		ft_printchr(char c);
size_t	ft_printstr(char *s);
void	ft_printptr(uintptr_t n);
void	ft_printdec(int n);
void	ft_printint(int n);
void	ft_printundec(unsigned int n);
void	ft_printhex(int n, char *b16);
void	ft_printpercent(void);

//misc functions
char	*ft_itoa(int n);
char	*ft_unitoa(unsigned int n);
size_t	ft_strlen(const char *str);

#endif
