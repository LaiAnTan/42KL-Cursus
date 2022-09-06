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
int		ft_countformat(char *str, int i);
int		ft_assignformat(t_flags *flag, char *str, int index, va_list args);

//handler functions
int	ft_mainhandler(t_flags *flag, va_list args);
int	ft_charhandler(va_list args);
int	ft_strhandler(va_list args);
int	ft_ptrhandler(va_list args);
int	ft_inthandler(t_flags *flag, va_list args);
int	ft_undechandler(t_flags *flag, va_list args);
int	ft_hexhandler(t_flags *flag, va_list args);
int	ft_percenthandler();

//print functions
int	ft_printflags(t_flags *flag);
int	ft_printsignflag(t_flags *flag, int num);
int	ft_printchr(char c);
int	ft_printint(t_flags *flag, int n);
int	ft_printundec(t_flags *flag, unsigned int n);
size_t	ft_printstr(char *s);
void	ft_printptr(uintptr_t n, char *b16);
void	ft_printhex(int n, char *b16);

//misc functions
char	*ft_itoa(int n);
char	*ft_unitoa(unsigned int n);
int	ft_counthex(int n);
size_t	ft_strlen(const char *str);


#endif
