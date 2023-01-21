SRCS = main.cpp			\

NAME = sedisforlosers

PARAMS = test.txt "test" "among us"

FLAGS = -Wall -Wextra -Werror -std=c++98

all : compile run

compile :
	@g++ $(FLAGS) $(SRCS) -o $(NAME)

run :
	@./$(NAME) $(PARAMS)