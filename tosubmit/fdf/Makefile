SRCS = fdf_main.c				\
		render.c				\
		parse_map.c				\
		parse_map_2.c			\
		get_next_line.c			\
		ft_split.c				\
		utils.c					\
		utils_2.c				\
		utils_gnl.c				\
		bresenham.c				\
		coordinates.c			\
		color.c					\

OBJ = $(SRCS:.c=.o)

NAME = fdf

MAP = maps/42.fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME) clean

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -lmlx -framework OpenGL -fsanitize=address -g3 -framework AppKit -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean :
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re : fclean all

run	: $(NAME)
	./$(NAME) $(MAP)

leaks : $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(MAP)