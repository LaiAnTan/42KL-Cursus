SRCS = fdf_main.c				\
		events.c				\
		render.c				\
		parse_map.c				\
		get_next_line.c			\
		ft_split.c				\
		utils.c					\
		utils_2.c				\
		utils_gnl.c				\
		bresenham.c				\
 
OBJ = $(SRCS:.c=.o)

NAME = fdf

MAP = maps/pyramide.fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME) clean

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

a_san:
	 -fsanitize=address
	
%.o : %.c
	@$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean :
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re : fclean all

run	: $(NAME)
	./$(NAME) $(MAP)

leaks : $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(MAP)