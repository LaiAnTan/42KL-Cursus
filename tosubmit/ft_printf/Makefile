# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 16:33:49 by tlai-an           #+#    #+#              #
#    Updated: 2022/09/15 15:24:39 by tlai-an          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_C =	ft_flags.c	\
				ft_format.c 		\
				ft_handlers1.c 		\
				ft_handlers2.c 		\
				ft_printers1.c 		\
				ft_printers2.c 		\
				ft_misc1.c 			\
				ft_misc2.c			\
				ft_printf_main.c	\

SRCS_H = ft_printf.h

SRCS_C_PATH = ./

SRCS = ${addprefix ${SRC_C_PATH}, ${SRCS_C}}

SRCS_O := ${SRCS_C:.c=.o}

CFLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

all : $(NAME)

.c.o :
		gcc ${CFLAG} -c -I ${SRCS_H} $< -o ${<:.c=.o}

bonus : fclean ${SRCS_O}
	ar r ${NAME} ${SRCS_O}

$(NAME): ${SRCS_O}
		ar rcs $(NAME) ${SRCS_O}

clean :
		rm -f ${SRCS_O}

fclean : clean
		rm -f $(NAME)

re : fclean all

git :
	git commit -am "e"
	git push
