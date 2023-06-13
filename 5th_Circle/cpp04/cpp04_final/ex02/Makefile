SRCS = main.cpp			\
		AAnimal.cpp		\
		Cat.cpp			\
		Dog.cpp			\
		WrongAnimal.cpp	\
		WrongCat.cpp	\
		Brain.cpp		\

NAME = abstract

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