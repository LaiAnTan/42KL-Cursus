SRCS = fdf_main.c
 
OBJ = $(SRCS:.c=.o)

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME) clean

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

a_san:
	 -fsanitize=address
	
%.o : %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all

run	: $(NAME)
	./$(NAME) $(MAP)