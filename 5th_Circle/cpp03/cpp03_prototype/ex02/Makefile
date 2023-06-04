SRCS = main.cpp			\
		ClapTrap.cpp	\
		ScavTrap.cpp	\
		FragTrap.cpp	\

NAME = fragtrap

PARAMS =

FLAGS = -Wall -Wextra -Werror -std=c++98

all : compile run

compile :
	@g++ $(FLAGS) $(SRCS) -o $(NAME)

run :
	@./$(NAME) $(PARAMS)