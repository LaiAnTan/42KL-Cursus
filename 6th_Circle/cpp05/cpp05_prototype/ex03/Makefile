SRCS =	main.cpp					\
		Bureaucrat.cpp				\
		AForm.cpp					\
		PresidentialPardonForm.cpp	\
		RobotomyRequestForm.cpp		\
		ShrubberyCreationForm.cpp	\
		Intern.cpp					\

NAME = Intern

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