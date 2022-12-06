#ifndef PIPEX_H

# define PIPEX_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <wait.h>

// child processes
pid_t	infile_cp(char **argv, char **envp, int *pipefd);
pid_t	outfile_cp(int argc, char **argv, char **envp, int *pipefd);
pid_t	heredoc_cp(char **argv, char **envp, int *pipefd);

// command execution
void	run_cmd(char *cmd_with_params, char **envp);
int		exec_cmd(char **cmd_paths, char **args, char **envp);

//command path locating
char	*get_path_envp(char **envp);
char	**get_cmd_path(char **envp, char *cmd);
char	*trim_path(char *path);
void	append_stuff(char **paths, char *cmd);

// file redirection
int		redirect_infile(char *infile_name);
int		redirect_outfile(char *outfile_name, char c);

//errors
int		error(void);

// gnl
char	*get_next_line(int fd);

//utils
size_t	ft_strlen(const char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s);
char	*ft_append(char *s1, char *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

#endif