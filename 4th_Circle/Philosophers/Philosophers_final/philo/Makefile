CFLAG = -Wall -Wextra -Werror

NAME = philo

SRCS_C =	actions.c		\
			checks.c		\
			data.c			\
			philo_main.c	\
			print.c			\
			pthread.c		\
			utils.c			\

SRCS_H = philo.h

SRCS_O = $(SRCS_C:.c=.o)

all : $(NAME)

%.o: %.c
		@gcc $(CFLAG) -c $< -o $(<:.c=.o)

$(NAME): $(SRCS_O)
		@gcc $(CFLAG) -o $(NAME) $(SRCS_O)

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

.PHONY: all clean fclean re git $(NAME)