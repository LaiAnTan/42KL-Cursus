SRCS = main.cpp					\
		BitcoinExchange.cpp		\

NAME = btc

PARAMS = input.txt

FLAGS = -Wall -Wextra -Werror -std=c++98

FSAN = -fsanitize=address

all : $(NAME)

$(NAME) :
	@g++ $(FLAGS) $(SRCS) -o $(NAME) $(FSAN)

run :
	@./$(NAME) $(PARAMS)

clean :
	@rm -f $(NAME)

re : clean all
