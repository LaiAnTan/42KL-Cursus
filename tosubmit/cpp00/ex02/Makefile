SRCS =	Account.cpp		\
		tests.cpp		\

NAME = log

PARAMS =

FLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : compile

compile :
	@g++ $(FLAGS) $(SRCS) -o $(NAME)

run :
	@./$(NAME) $(PARAMS)

clean :
		@rm -f $(NAME)

re : clean all 

.PHONY: all compile run clean fclean re $(NAME)