#ifndef LIBFTPRINTF
#define LIBFTPRINTF

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

//main
int		ft_printf(const char *format, ...);

//flags
typedef struct s_flags
{
	int				signflag;
	int				hashflag;
	int				spaceflag;
	int				type;
}					t_flags;

//format struct functions
t_flags	*ft_genflag(void);
void	ft_resetflag(t_flags *flag);
int		ft_countflag(char *str, int i);
int		ft_assignformat(t_flags *flag, char *str, int index, va_list args);

//handler functions
int	ft_mainhandler(t_flags *flag, va_list args);
int	ft_charhandler(t_flags *flag, va_list args);
int	ft_strhandler(t_flags *flag, va_list args);
int	ft_ptrhandler(t_flags *flag, va_list args);
int	ft_inthandler(t_flags *flag, va_list args);
int	ft_undechandler(t_flags *flag, va_list args);
int	ft_hexhandler(t_flags *flag, va_list args);
int	ft_percenthandler(t_flags *flag, va_list args);

//print functions
int	ft_printflags(t_flags *flag);
int	ft_printsignflag(t_flags *flag, int num);
int	ft_printchr(char c);
int	ft_printint(int n);
int	ft_printundec(unsigned int n);
size_t	ft_printstr(char *s);
int	ft_printptr(int count, uintptr_t n, char *b16);
int	ft_printhex(int count, int n, char *b16);

//misc functions
char	*ft_itoa(int n);
char	*ft_unitoa(unsigned int n);
size_t	ft_strlen(const char *str);

#endif
