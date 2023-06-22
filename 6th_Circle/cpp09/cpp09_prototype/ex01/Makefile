SRCS = main.cpp		\
		RPN.cpp		\

NAME = RPN

PARAMS = "8 9 * 9 - 9 - 9 - 4 - 1 +"

FLAGS = -Wall -Wextra -Werror -std=c++98

FSAN = -fsanitize=address

all : $(NAME)

$(NAME) :
	@g++ $(FLAGS) $(SRCS) -o $(NAME) $(FSAN)

run :
	@./$(NAME) $(PARAMS)

clean :
	@rm -f $(NAME)

re : clean all
