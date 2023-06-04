#ifndef MINISHELL_H

#define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
// ini untuk ubuntu sahaja
// # include <wait.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <limits.h>
// # include <linux/limits.h>
# include <signal.h>
# include <termios.h>
# include <fcntl.h>

// struct for environment variables
typedef struct s_env
{
	char			*str;
	int				printed;
}		t_env;

// struct for commands
typedef struct s_cmd
{
	char			**cmd;
}		t_cmd;

typedef struct s_sig
{
	struct termios	def_attributes;
	struct termios	mod_attributes;
}		t_sig;

// linked list that holds environmental variables and commands (shit name)
typedef struct s_list
{
	int				in_fd;
	int				out_fd;

	t_env			env;
	t_cmd			cmd;

	struct s_list	*next;

}		t_list;

// all data for program

// WHY THE FUCK DID WE USE DOUBLE CHAR POINTERS
// I AM IN SO MUCH PAIN NOW
typedef struct s_data
{
	int		stdin_backup;
	int		stdout_backup;
	int		last_exit;

	char	*line;
	char	*cwd;
	char	**tokens;
	char	**my_envp;
	
	t_sig	*attr;
	t_list	*vars;
	t_list	*cmds;

}			t_data;

/* Input Processing */

int		lexer(t_data *data);
int		parser(t_data *data);
int		expander(t_data *data);
int		get_keyword(char *line, int stop);

/* Redirection */
int		is_redirect(char *arg);
int		get_redirect_type(char *arg);
int		contains_redirect(char **args);
int		handle_redirect(char **args, int *in_fd, int *out_fd, int std_in);

int		handle_redir_input(char *filename, int *in_fd);
int		handle_redir_output(char *filename, int *out_fd);
int		handle_redir_input_heredoc(char *delimiter, int *in_fd, int std_in);
int		handle_redir_output_append(char *filename, int *out_fd);

char	**get_cmd_args_without_redirect(char **args);

/* Command Processing */

void	run_cmd(t_data *data);
void	append_stuff(char **paths, char *cmd);

int		exec_cmd(t_data *data, char **cmd_paths, char **args, char *cmd);

char	*trim_path(char *path);
char	*get_path_envp(t_data *data);
char	**get_cmd_path(t_data *data, char *cmd);

/* Environment Variables */

t_list	*set_env(char **envp);
t_list	*find_var(t_list *vars, char *to_find);

void	rebuild_envp(t_data *data);

int		get_equal_pos(t_list *node);

char	*get_val(t_list *node);
char	*access_var(t_data *data, char *name);

/* Signals */

void	reset_attr(t_data *data);
void	modify_attr(t_data *data);
void	new_line_handler(int sig_code);

/* Builtin command functions */

int		builtin_echo(char **args);
int		builtin_pwd(t_data *data);
int		builtin_env(t_data *data);
int		builtin_exit(char **args);
int		builtin_cd(char **args, t_data *data);
int		builtin_unset(char **args, t_data *data);
int		builtin_export(char **args, t_data *data);
int		handle_builtins(char *cmd, char **args, t_data *data);

/* Linked Lists */

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew_env(char *var);
t_list	*ft_lstnew_cmd(char **cmd);


void	ft_lstfree(t_list **lst);
void	ft_lstprint_env(t_list *lst);
void	ft_lstdel_env(t_list **lst, t_list *node);
void	ft_lstadd_back(t_list **lst, t_list *new);

int		ft_lstsize(t_list *lst);

/* Utility Functions */

void	free_2d_array(char ***arr);

int		ft_strlen(char *s);
int		is_numeric(char *str);
int		ft_atoi(const char *s);
int		count_2d_array(char **e);
int		ft_strcmp(char *s1, char *s2);
int		ft_strcmp_equals(char *s1, char *s2);

char	*ft_itoa(int n);
char	*ft_strdup(char *str);
char	*ft_append(char *s1, char *s2);
char	*ft_trimstr(char *source, char to_trim);
char	*ft_substr(char *s, unsigned int start, unsigned int end);

char	**ft_split(char *s, char c);
char	**realloc_append(char **src, char *str);


int	is_token(char c);

#endif