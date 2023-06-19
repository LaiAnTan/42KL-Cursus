NAME = minishell

ODIR = obj

SRCS_C =	srcs/builtins/builtins_cd.c					\
            srcs/builtins/builtins_echo.c				\
            srcs/builtins/builtins_exit.c				\
			srcs/builtins/builtins_export_helpers.c		\
            srcs/builtins/builtins_export.c				\
            srcs/builtins/builtins_handler_env_pwd.c	\
            srcs/builtins/builtins_unset.c				\
            srcs/cmd/cmd_execute_helpers.c				\
            srcs/cmd/cmd_execute_multiple.c				\
            srcs/cmd/cmd_execute.c						\
            srcs/cmd/cmd_paths_helpers.c				\
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
            srcs/vars/vars_expansion_helpers.c			\
            srcs/vars/vars_expansion.c					\
            srcs/vars/vars_helpers_1.c					\
            srcs/vars/vars_helpers_2.c					\
			srcs/error_exit.c							\
			srcs/lexer_helpers.c						\
            srcs/lexer.c								\
            srcs/main.c									\
            srcs/parser.c								\
            srcs/signal.c								\

SRCS_H := headers/minishell.h

CFLAGS := -Wall -Wextra -Werror

# FSAN = -fsanitize=address -g

INCS := -I/usr/local/opt/readline/include

LIBS := -lreadline -L/usr/include -L/usr/local/opt/readline/lib

SRCS_O := $(addprefix $(ODIR)/,$(notdir $(SRCS_C:.c=.o)))

vpath %.c srcs/builtins:srcs/cmd:srcs/redirection:srcs/utils:srcs/vars:srcs

# Colors
L_RESET = \e[1K\r
C_CYAN = \033[0;96m
C_GREEN = \033[0;92m
C_RESET = \033[0m


all : $(NAME)

$(NAME): $(SRCS_O)
	@gcc ${CFLAGS} $^ $(LIBS) -o $@
	@printf "$(L_RESET)$(C_GREEN)Done!$(C_RESET)\n"

$(ODIR) :
	@mkdir -p $@

$(ODIR)/%.o: %.c | $(ODIR)
	@gcc $(CFLAGS) $(INCS) -c $< -o $@
	@printf "$(L_RESET)$(C_RESET)Creating object file $(C_CYAN)$@$(C_RESET) from $(C_CYAN)$<$(C_RESET)"

run :
	@./$(NAME)

vg :
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

clean :
	@echo 'Removing executable files...'
	@rm -rf $(NAME)

fclean : clean
	@echo "Removing executable $(NAME) and object file folder $(ODIR)..."
	@rm -f $(NAME)
	@rm -rf $(ODIR)

re : fclean all

.PHONY: all clean fclean re