# include "../headers/minishell.h"

/*
modifies the terminal attributes to silence signals using the modified termios structure 
*/
void	modify_attr(t_data *data)
{
	data->attr->mod_attributes.c_iflag &= ~(ICANON | ECHO | ISIG);
    data->attr->mod_attributes.c_cc[VMIN] = 1;
    data->attr->mod_attributes.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &data->attr->mod_attributes);
}

/*
resets the terminal attributes using the default termios structure saved
*/
void	reset_attr(t_data *data)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &data->attr->def_attributes);
}

/*
function that handles the printing of a new line after a signal is sent
used as the signal handler for SIGINT (Ctrl + C)
*/
void	new_line_handler(int sig_code)
{
	(void) sig_code;

	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
