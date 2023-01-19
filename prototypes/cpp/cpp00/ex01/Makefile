SRCS_CPP =	Contact.cpp		\
			PhoneBook.cpp	\

SRCS_H = MyAwesomePhonebook.hpp

NAME = MyAwesomePhonebook

PARAMS =

FLAGS = -Wall -Wextra -Werror -std=c++98

all : compile run

compile :
	@g++ $(FLAGS) $(SRCS_CPP) -o $(NAME)

run :
	@./$(NAME) $(PARAMS)

all : $(NAME)