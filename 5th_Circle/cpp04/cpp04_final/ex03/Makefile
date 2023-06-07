SRCS =	main.cpp		\
		AMateria.cpp	\
		Character.cpp	\
		Cure.cpp		\
		Ice.cpp			\
		MateriaSource.cpp

NAME = amateria

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

.PHONY: all compile run clean re $(NAME)