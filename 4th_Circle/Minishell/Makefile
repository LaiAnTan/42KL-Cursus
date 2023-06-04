NAME = minishell

CDIR = srcs

ODIR = obj

SRCS_C =	srcs/builtins/builtins_cd.c					\
			srcs/builtins/builtins_echo.c				\
			srcs/builtins/builtins_exit.c				\
			srcs/builtins/builtins_export.c				\
			srcs/builtins/builtins_handler_env_pwd.c	\
			srcs/builtins/builtins_unset.c				\
			srcs/cmd/cmd_execute.c						\
			srcs/cmd/cmd_paths.c						\
			srcs/redirection/redirection_handlers.c		\
			srcs/redirection/redirection_helpers.c		\
			srcs/redirection/redirection_mains.c		\
			srcs/utils/utils_2d_array.c					\
			srcs/utils/utils_list_1.c					\
			srcs/utils/utils_list_2.c					\
			srcs/utils/utils_string_1.c					\
			srcs/utils/utils_string_2.c					\
			srcs/utils/utils_string_itoa.c				\
			srcs/utils/utils_string_split.c				\
			srcs/vars/vars_handler.c					\
			srcs/vars/vars_helpers_1.c					\
			srcs/vars/vars_helpers_2.c					\
			srcs/lexer.c								\
			srcs/main.c									\
			srcs/parser.c								\
			srcs/signal.c								\

SRCS_H = headers/minishell.h

SRCS_O = $(SRCS_C:.c=.o)

CFLAG = -Wall -Wextra -Werror

# FSAN = -fsanitize=address -g

LIB = -lreadline

all : $(NAME) move

%.o:%.c
		@gcc $(CFLAG) -c $< -o $(<:.c=.o)

$(NAME): $(SRCS_O)
		@gcc $(CFLAG) -o $(NAME) $(SRCS_O) $(LIB) ${FSAN}

$(ODIR) :
	@echo "Folder $(ODIR) does not exist, making a new one..."
	@mkdir $@

move : $(ODIR)
	@echo "Storing object files into $(ODIR)..."
	@mv $(SRCS_O) $(ODIR)

run :
	@./$(NAME)

vg :
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

clean :
	@echo "Removing object files..."
	@rm -f $(ODIR)/*.o

fclean : clean
	@echo "Removing executable $(NAME) and folder $(ODIR)..."
	@rm -f $(NAME)
	@rmdir $(ODIR)

re : fclean all

.PHONY: all clean fclean re git $(NAME)