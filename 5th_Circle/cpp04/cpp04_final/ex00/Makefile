SRCS = main.cpp			\
		Animal.cpp		\
		Cat.cpp			\
		Dog.cpp			\
		WrongAnimal.cpp	\
		WrongCat.cpp	\

NAME = animal

PARAMS =

FLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) :
	@g++ $(FLAGS) $(SRCS) -o $(NAME)

run :
	@./$(NAME) $(PARAMS)

clean :
	@rm -f $(NAME)

re : clean all

.PHONY: all compile run clean re