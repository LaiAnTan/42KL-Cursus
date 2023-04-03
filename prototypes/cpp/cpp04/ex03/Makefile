SRCS =	main.cpp		\
		AMateria.cpp	\
		Character.cpp	\
		Cure.cpp		\
		Ice.cpp			\
		MateriaSource.cpp

NAME = AMateria

PARAMS =

FLAGS = -Wall -Wextra -Werror -std=c++98

all : compile run

compile :
	@g++ $(FLAGS) $(SRCS) -o $(NAME)

run :
	@./$(NAME) $(PARAMS)

leaks:
	@valgrind --leak-check=full ./$(NAME) $(PARAMS)