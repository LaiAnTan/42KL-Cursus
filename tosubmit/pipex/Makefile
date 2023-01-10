# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 16:33:49 by tlai-an           #+#    #+#              #
#    Updated: 2023/01/10 14:36:09 by tlai-an          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAG = -Wall -Wextra -Werror

NAME = pipex

SRCS_C =	pipex_main.c	\
			cmd.c			\
			file.c			\
			error.c			\
			utils.c			\
			paths.c			\
			ft_split.c		\
			get_next_line.c	\

SRCS_H = pipex.h

SRCS_O = $(SRCS_C:.c=.o)

all : $(NAME)

%.o: %.c
		@gcc $(CFLAG) -c $< -o $(<:.c=.o)

$(NAME): $(SRCS_O)
		@gcc $(CFLAG) -o $(NAME) $(SRCS_O)

clean :
		@rm -f ${SRCS_O}

fclean : clean
		@rm -f $(NAME)

re : fclean all

git :
	git commit -am "e"
	git push

.PHONY: all clean fclean re git $(NAME)