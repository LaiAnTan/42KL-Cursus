SRCS =	main.cpp		\
		Serializer.cpp	\


NAME = Serialization

PARAMS =

FLAGS = -Wall -Wextra -Werror -std=c++98

all : compile run

compile :
	@g++ $(FLAGS) $(SRCS) -o $(NAME)

run :
	@./$(NAME) $(PARAMS)

clean:
	@rm $(NAME)

leaks:
	@valgrind --leak-check=full ./$(NAME) $(PARAMS)