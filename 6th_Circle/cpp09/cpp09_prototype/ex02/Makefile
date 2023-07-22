SRCS = main.cpp		\
		PmergeMe.cpp		\

NAME = PmergeMe

PARAMS = 1 4 18 7 26 91 64 58 12 67
FLAGS = -Wall -Wextra -Werror -std=c++98

FSAN = -fsanitize=address

all : $(NAME)

$(NAME) :
	@g++ $(FLAGS) $(SRCS) -o $(NAME) $(FSAN)

run :
	@./$(NAME) $(PARAMS)

clean :
	@rm -f $(NAME)

vg : re
	valgrind --leak-check=full ./$(NAME) $(PARAMS)

re : clean all