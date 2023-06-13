NAME = minishell

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

SRCS_H := headers/minishell.h

CFLAGS := -Wall -Wextra -Werror

# FSAN = -fsanitize=address -g

INCS := -I/usr/local/opt/readline/include

LIBS := -L/usr/include -L/usr/local/opt/readline/lib -lreadline

SRCS_O := $(addprefix $(ODIR)/,$(notdir $(SRCS_C:.c=.o)))

vpath %.c srcs/builtins:srcs/cmd:srcs/redirection:srcs/utils:srcs/vars:srcs

all : $(NAME)

$(NAME): $(SRCS_O)
	@gcc ${CFLAGS} $^ $(LIBS) -o $@
	@echo -e '\e[K\033[92mDone!\e[K\033[92m'

$(ODIR) :
	@mkdir -p $@

$(ODIR)/%.o: %.c | $(ODIR)
	@gcc $(CFLAGS) $(INCS) -c $< -o $@
	@echo -e '\e[1A\e[K\033[0mCreating object file \033[0;96m$@\033[0m from \033[0;96m $<'

run :
	@./$(NAME)

vg :
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

clean :
	@echo -e 'Removing object files...'

fclean : clean
	@echo "Removing executable $(NAME) and folder $(ODIR)..."
	@rm -f $(NAME)
	@rm -rf $(ODIR)

re : fclean all

test :
	@echo $(SRCS_O)

.PHONY: all clean fclean re