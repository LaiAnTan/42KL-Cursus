SRCS = megaphone.cpp

NAME = megaphone

PARAMS = "shhhhh... I think the students are asleep..."

#  Damnit " ! " "Sorry students, I thought this thing was off."

FLAGS = -Wall -Wextra -Werror -std=c++98

all : compile run

compile :
	@g++ $(FLAGS) $(SRCS) -o $(NAME)

run :
	@./$(NAME) $(PARAMS)