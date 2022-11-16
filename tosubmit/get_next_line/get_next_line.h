/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:19:57 by tlai-an           #+#    #+#             */
/*   Updated: 2022/11/16 18:39:42 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

/* BUFFER_SIZE = size of temporary storage area */
#  define BUFFER_SIZE 42

# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);

int		check_nl(char *str, int size);
char	*transfer(int fd, char *buffer, char *content);
char	**seperate_nl(char *str);

size_t	ft_strlen(char *str);
char	*ft_append(char *s1, char *s2);
char	*ft_strdup(char *str);

#endif