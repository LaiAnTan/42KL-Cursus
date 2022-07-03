SRCS_C = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c

SRCS_H = libft.h

SRCS_C_PATH = ./

SRCS = ${addprefix ${SRC_C_PATH}, ${SRCS_C}}

SRCS_O := ${SRCS_C:.c =.o}

CFLAG = -Wall -Wextra -Werror

LIB = libft.a

all : ${LIB}

.c.o :
		gcc ${CFLAG} -c -I ${SRCS_H} $< -o ${<:.c=.o}

libft.a	: ${SRCS_O}
		ar rcs ${LIB} ${SRCS_O}

clean :
		rm -f {SRCS_O}

fclean : clean
		rm -f {LIB}

re : fclean all
