/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:20:56 by tlai-an           #+#    #+#             */
/*   Updated: 2022/09/12 13:43:43 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int				signflag;
	int				hashflag;
	int				spaceflag;
	int				type;
}					t_flags;

/* ft_printf_main.c */
int		ft_printf(const char *format, ...);

/* ft_flags.c */
t_flags	*ft_genflag(void);
int		ft_resetflag(t_flags *flag);
int		ft_countformat(char *str, int i);

/* ft_format.c */
int		ft_assignformat(t_flags *flag, char *str, int index, va_list args);

/* ft_handlers1.c */
int		ft_mainhandler(t_flags *flag, va_list args);
int		ft_charhandler(va_list args);
int		ft_strhandler(va_list args);
int		ft_ptrhandler(va_list args);
int		ft_inthandler(t_flags *flag, va_list args);

/* ft_handlers2.c */
int		ft_undechandler(t_flags *flag, va_list args);
int		ft_hexhandler(t_flags *flag, va_list args);
int		ft_percenthandler(void);

/* ft_printers1.c */
int		ft_printchr(char c);
size_t	ft_printstr(char *s);
void	ft_printptr(uintptr_t n, char *b16);
void	ft_printhex(int n, char *b16);

/* ft_printers2.c */
int		ft_printint(t_flags *flag, int n);
int		ft_printundec(t_flags *flag, unsigned int n);
int		ft_printflags(t_flags *flag);
int		ft_printsignflag(t_flags *flag, int num);

/* ft_misc.c */
char	*ft_itoa(int n);
char	*ft_unitoa(unsigned int n);
int		ft_counthex(unsigned int n);
size_t	ft_strlen(const char *str);

#endif
