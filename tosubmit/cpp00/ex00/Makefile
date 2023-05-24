SRCS = megaphone.cpp

NAME = megaphone

PARAMS = "shhhhh... I think the students are asleep..."

#  Damnit " ! " "Sorry students, I thought this thing was off."

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