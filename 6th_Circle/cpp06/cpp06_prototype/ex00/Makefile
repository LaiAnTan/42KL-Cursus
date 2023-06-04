SRCS =	main.cpp			\
		ScalarConverter.cpp	\
		convertHelpers.cpp	\

NAME = ScalarConverter

PARAMS =

FLAGS = -Wall -Wextra -Werror -std=c++98

all : re

compile :
	@g++ $(FLAGS) $(SRCS) -o $(NAME)

run :
	@./$(NAME) $(PARAMS)

clean:
	@rm $(NAME)

leaks:
	@valgrind --leak-check=full ./$(NAME) $(PARAMS)

re: compile