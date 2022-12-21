# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 16:33:49 by tlai-an           #+#    #+#              #
#    Updated: 2022/12/21 17:38:49 by tlai-an          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_C =	mandatory/sort.c				\
			mandatory/swap.c				\
			mandatory/push.c				\
			mandatory/stack.c				\
			mandatory/utils.c				\
			mandatory/errors.c				\
			mandatory/rotate.c				\
			mandatory/revrotate.c			\
			mandatory/radixsort.c			\
			mandatory/push_swap_main.c		\

BONUS_C =	bonus/check.c					\
			bonus/checker_main.c			\
			bonus/errors.c					\
			bonus/get_next_line.c			\
			bonus/gnl_utils.c				\
			bonus/push.c					\
			bonus/revrotate.c				\
			bonus/rotate.c					\
			bonus/stack.c					\
			bonus/swap.c					\
			bonus/utils.c					\


BONUS_H = checker.h
			
SRCS_H = push_swap.h

SRCS_C_PATH = ./

SRCS = ${addprefix ${SRC_C_PATH}, ${SRCS_C}}

SRCS_O = $(SRCS_C:.c=.o)

BONUS_O = $(BONUS_C:.c=.o)

CFLAG = -Wall -Wextra -Werror

NAME = push_swap

BONUS = checker

all : $(NAME)

.c.o :
		gcc ${CFLAG} -c -I ${SRCS_H} $< -o ${<:.c=.o}

$(NAME): ${SRCS_O}
		gcc $(CFLAG) -o $(NAME) $(SRCS_O)

bonus : ${BONUS_O}
		gcc $(CFLAG) -o $(BONUS) $(BONUS_O)

clean :
		rm -f ${SRCS_O}

fclean : clean
		rm -f $(NAME)

bonus : re
	

re : fclean all

git :
	git commit -am "e"
	git push
