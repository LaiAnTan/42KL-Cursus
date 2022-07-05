#ifndef LIBFT
#define LIBFT


// libraries
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>

// boolean
int 	ft_isalpha(int a);
int 	ft_isdigit(int a);
int 	ft_isalnum(int a);
int 	ft_isascii(int a);
int 	ft_isprint(int a);

// character
int 	ft_tolower(int a);
int 	ft_toupper(int a);

// memory
void 	ft_bzero(void *s, size_t n);
void 	*ft_calloc(size_t nmemb, size_t size);
void 	*ft_memcpy(void *d, const void *s, size_t n);
void 	*ft_memmove(void *d, const void *s, size_t n);
void 	*ft_memchr(const void *s, int c, size_t n);
void 	*ft_memset(void *s, int c, size_t n);
int 	ft_memcmp(const void *s1, const void *s2, size_t n);

// string
int		ft_atoi(const char *s);
int 	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
size_t 	ft_strlcat(char *dst, const char *src, size_t size);
size_t 	ft_strlcpy(char *dst, const char *src, size_t size);
char 	*ft_strdup(const char *s);
char 	*ft_strchr(const char *s, int c);
char 	*ft_strrchr(const char *s, int c);
char 	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char 	*ft_strtrim(char const *s1, char const *set);
char 	**ft_split(char const *s, char c);

#endif

