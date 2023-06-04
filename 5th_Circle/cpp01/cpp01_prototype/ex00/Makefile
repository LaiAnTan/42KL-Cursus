SRCS = main.cpp			\
		Zombie.cpp		\
		newZombie.cpp	\
		randomChump.cpp	\

NAME = zombie

PARAMS = 

FLAGS = -Wall -Wextra -Werror -std=c++98

all : compile run

compile :
	@g++ $(FLAGS) $(SRCS) -o $(NAME)

run :
	@./$(NAME) $(PARAMS)