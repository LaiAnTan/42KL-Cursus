# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 16:33:49 by tlai-an           #+#    #+#              #
#    Updated: 2023/01/05 10:24:20 by tlai-an          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAG = -Wall -Wextra -Werror

NAME = push_swap

SRCS_C =	mandatory/push_swap_main.c		\
			mandatory/sort.c				\
			mandatory/radixsort.c			\
			mandatory/stack.c				\
			mandatory/errors.c				\
			mandatory/swap.c				\
			mandatory/push.c				\
			mandatory/rotate.c				\
			mandatory/revrotate.c			\
			mandatory/ft_split.c			\
			mandatory/utils.c				\
			mandatory/utils_2.c				\
			mandatory/utils_3.c				\

SRCS_H = mandatory/push_swap.h

SRCS_O = $(SRCS_C:.c=.o)

BONUS = checker

BONUS_C =	bonus/checker_main.c			\
			bonus/check.c					\
			bonus/stack.c					\
			bonus/errors.c					\
			bonus/swap.c					\
			bonus/push.c					\
			bonus/rotate.c					\
			bonus/revrotate.c				\
			bonus/ft_split.c				\
			bonus/get_next_line.c			\
			bonus/utils.c					\
			bonus/utils_2.c					\
			bonus/gnl_utils.c				\

BONUS_H = bonus/checker.h

BONUS_O = $(BONUS_C:.c=.o)

all : $(NAME)

%.o: %.c
		@gcc $(CFLAG) -c $< -o $(<:.c=.o)

$(NAME): $(SRCS_O)
		@gcc $(CFLAG) -o $(NAME) $(SRCS_O)

bonus : re $(BONUS_O)
		@gcc $(CFLAG) -o $(BONUS) $(BONUS_O)

clean :
		@rm -f ${SRCS_O}
		@rm -f ${BONUS_O}

fclean : clean
		@rm -f $(NAME)
		@rm -f $(BONUS)

re : fclean all

git :
	git commit -am "e"
	git push

.PHONY: all clean fclean re bonus git $(NAME)