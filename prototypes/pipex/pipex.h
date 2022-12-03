#ifndef PIPEX_H

# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

int	run_cmd(char **cmd_paths, char **args, char **envp);

//command paths
char	*get_path_envp(char **envp);
char	**get_cmd_path(char **envp, char *cmd);
char	*trim_path(char *path);
void	append_stuff(char **paths, char *cmd);

//error
int		error(void);

//utils
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_append(char *s1, char *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

#endif