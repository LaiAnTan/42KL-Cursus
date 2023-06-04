SRCS = main.cpp			\
		Fixed.cpp		\
		bsp.cpp			\
		Point.cpp		\

NAME = bsp

PARAMS =

#-Wall -Wextra -Werror

FLAGS =  -std=c++98

all : compile run

compile :
	@g++ $(FLAGS) $(SRCS) -o $(NAME)

run :
	@./$(NAME) $(PARAMS)