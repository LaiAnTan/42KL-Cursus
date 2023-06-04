SRCS = main.cpp			\
		Harl.cpp		\

NAME = harlFilter

PARAMS = "WARNING"

FLAGS = -Wall -Wextra -Werror -std=c++98

all : compile run

compile :
	@g++ $(FLAGS) $(SRCS) -o $(NAME)

run :
	@./$(NAME) $(PARAMS)