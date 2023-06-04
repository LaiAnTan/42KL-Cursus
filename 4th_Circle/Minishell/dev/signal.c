# include "../headers/minishell.h"

void	modify_attr(t_data *data)
{
	data->attr->mod_attributes.c_iflag &= ~(ICANON | ECHO | ISIG);
    data->attr->mod_attributes.c_cc[VMIN] = 1;
    data->attr->mod_attributes.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &data->attr->mod_attributes);
}

void	reset_attr(t_data *data)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &data->attr->def_attributes);
}

void	new_line_handler(int sig_code)
{
	(void) sig_code;

	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	exit_handler(int sig_code)
{
	(void) sig_code;
	
	exit(0); // exit auto free
}

