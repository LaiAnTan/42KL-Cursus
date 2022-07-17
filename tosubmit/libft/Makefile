# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/17 16:15:28 by tlai-an           #+#    #+#              #
#    Updated: 2022/07/17 16:15:36 by tlai-an          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_C = 	ft_isalpha.c	\
			ft_isdigit.c 	\
			ft_isalnum.c 	\
			ft_isascii.c 	\
			ft_isprint.c 	\
			ft_strlen.c  	\
			ft_memset.c  	\
			ft_bzero.c   	\
			ft_memcpy.c  	\
			ft_memmove.c 	\
			ft_strlcpy.c 	\
			ft_strlcat.c 	\
			ft_toupper.c 	\
			ft_tolower.c 	\
			ft_strchr.c  	\
		 	ft_strrchr.c 	\
			ft_strncmp.c 	\
			ft_memchr.c  	\
			ft_memcmp.c  	\
			ft_strnstr.c 	\
		 	ft_atoi.c    	\
			ft_calloc.c  	\
			ft_strdup.c  	\
			ft_substr.c  	\
			ft_strjoin.c 	\
			ft_strtrim.c 	\
			ft_split.c   	\
			ft_itoa.c    	\
			ft_strmapi.c 	\
			ft_striteri.c 	\
			ft_putchar_fd.c \
			ft_putstr_fd.c 	\
			ft_putendl_fd.c \
			ft_putnbr_fd.c	\

SRCS_H = libft.h

SRCS_C_PATH = ./

SRCS = ${addprefix ${SRC_C_PATH}, ${SRCS_C}}

SRCS_O := ${SRCS_C:.c=.o}

CFLAG = -Wall -Wextra -Werror

NAME = libft.a

all : $(NAME)

.c.o :
		gcc ${CFLAG} -c -I ${SRCS_H} $< -o ${<:.c=.o}

$(NAME): ${SRCS_O}
		ar rcs $(NAME) ${SRCS_O}

clean :
		rm -f ${SRCS_O}

fclean : clean
		rm -f $(NAME)

re : fclean all
