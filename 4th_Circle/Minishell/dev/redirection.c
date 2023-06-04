#include "../headers/minishell.h"

/*
--redirection--

< should redirect input.
> should redirect output.
<< should be given a delimiter, then read the input until a line containing the
delimiter is seen. However, it doesn’t have to update the history!
>> should redirect output in append mode.

redirections are handled left to right no matter what

redirection identifier without a (*) is an error
(*) input redirection : existing filename only
(*) output redirection : existing / potential filename

eg: ls > a > b > c
output: files a, b and c are created, but the output is written only inside c

eg: cat < a < b < c
output: only file c is redirected as input

eg: cat < a << EOF < c
output: STDIN is read until EOF is found, only then file c is redirected as input

eg: cat < a b
output: b is output since cat reads from parameter first 

for multiple commands:
redirections should be done inside the child process, 
but before the alteration of the command's input and output
this is because redirections override piping

*/

int		is_redirect(char *arg)
{
	if (ft_strcmp(arg, ">") == 0 || ft_strcmp(arg, ">>") == 0 
		|| ft_strcmp(arg, "<") == 0 || ft_strcmp(arg, "<<") == 0)
	{
		return (1);
	}
	return (0);
}

int	handle_redir_input(char *filename, int *in_fd)
{
	int		fd;

	if (is_redirect(filename))
		return (-1);
	fd = open(filename, O_RDONLY, 0777);
	if (fd == -1)
	{
		printf("%s: file could not be open", filename); // handle later
		return (-1);
	}
	dup2(fd, *in_fd);
	return (1);
}

int	handle_redir_input_heredoc(char *delimiter, int *in_fd)
{
	int		storage[2]; // 0 - read 1 - write
	char	*line;

	if (is_redirect(delimiter))
		return (-1);
	printf("in handle_redir_input_heredoc, delim = %s, in_fd = %d\n", delimiter, *in_fd);
	pipe(storage);
	line = NULL;
	while (1)
	{
		line = readline("> ");
		rl_redisplay();
		if (ft_strcmp(line, delimiter) == 0)
			break ;
		write(storage[1], line, ft_strlen(line));
		write(storage[1], "\n", 1);
		free(line);
	}
	dup2(storage[0], *in_fd);
	close(storage[1]);
	close(storage[2]);
	return (1);
}

int	handle_redir_output(char *filename, int *out_fd)
{
	int	fd;

	if (is_redirect(filename))
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		printf("%s: file could not be open", filename); // handle later
		return (-1);
	}
	dup2(fd, *out_fd);
	close(fd);
	return (1);
}

int	handle_redir_output_append(char *filename, int *out_fd)
{
	int	fd;

	if (is_redirect(filename))
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0777);
	if (fd == -1)
	{
		printf("%s: file could not be open", filename); // handle later
		return (-1);
	}
	dup2(fd, *out_fd);
	close(fd);
	return (1);
}

int		contains_redirect(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		if (is_redirect(args[i]))
			return (1);
		i++;
	}
	return (0);
}

int		get_redirect_type(char *arg)
{
	if (!is_redirect(arg))
		return (0);
	if (ft_strcmp(arg, ">") == 0)
		return (1);
	if (ft_strcmp(arg, ">>") == 0)
		return (2);
	if (ft_strcmp(arg, "<") == 0)
		return (3);
	if (ft_strcmp(arg, "<<") == 0)
		return (4);
}

int		*get_next_redirect(char **args, int index)
{
	int	*redirect_info; // 0 - type 1 - index

	if (index >= count_2d_array(args))
		return (NULL);
	redirect_info = (int *) malloc(sizeof(int) * 2);
	while (args[index] != NULL)
	{
		redirect_info[0] = get_redirect_type(args[index]);
		
		if (redirect_info[0] != 0)
		{
			redirect_info[1] = index;
			return (redirect_info);
		}
		++index;
	}
	redirect_info[0] = -1;
	redirect_info[1] = -1;
	return (redirect_info);
}

int		count_args_without_redirect(char **args)
{
	int		i;
	int		len;
	int		count;
	
	i = 0;
	len = count_2d_array(args);
	count = 0;
	while (i < len)
	{
		if (is_redirect(args[i]))
			i += 2;
		else
		{
			++i;
			++count;
		}
	}
	return (count);
}

char	**get_cmd_args_without_redirect(char **args)
{
	int		i;
	int		j;
	int		old_len;
	int		new_len;
	char	**new;

	if (contains_redirect(args) == 0)
		return (args);
	i = 0;
	j = 0;
	old_len = count_2d_array(args);
	new_len = count_args_without_redirect(args);
	new = malloc (sizeof(char *) * (new_len + 1));
	while (i < old_len)
	{
		if (is_redirect(args[i]))
			i += 2;
		else
		{
			new[j] = ft_strdup(args[i]);
			++i;
			++j;
		}
		printf("i = %d j = %d\n", i, j);
	}
	new[new_len] = NULL;
	free_2d_array(&args);
	return (new);
}

int		handle_redirect(char **args, int *in_fd, int *out_fd)
{
	int		i;
	int		error;
	int		*redirect_info; // 0 - type 1 - index

	i = 0;
	error = 0;
	if (contains_redirect(args) == 0)
		return (0);
	while (args[i] != NULL)
	{
		redirect_info = get_next_redirect(args, i);

		if (redirect_info == NULL)
			return (0); // error
		else if (redirect_info[0] == -1 && redirect_info[1] == -1)
			return (1); // done

		i = redirect_info[1] + 1;
		if (redirect_info[0] == 1)
			error = handle_redir_output(args[i], out_fd);
		else if (redirect_info[0] == 2)
			error = handle_redir_output_append(args[i], out_fd);
		else if (redirect_info[0] == 3)
			error = handle_redir_input(args[i], in_fd);
		else if (redirect_info[0] == 4)
			error = handle_redir_input_heredoc(args[i], in_fd);

		if (error == -1)
			return (0); // error

		free(redirect_info);
	}
	return (1); // done
}