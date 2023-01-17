#include "philo.h"

void	print_action(t_data *data, long unsigned int curr_time, int philo_num, int action)
{
	char	*num;
	char	*time;

	num = ft_itoa(philo_num);
	time = ft_itoa(curr_time);
	pthread_mutex_lock(&data->print_mtx);
	if (data->dead == 0)
	{
		write(STDOUT_FILENO, time, ft_strlen(time));
		write(STDOUT_FILENO, " ", 1);
		write(STDOUT_FILENO, num, ft_strlen(num));
	if (action == 1 && data->dead != 1)
		write(STDOUT_FILENO, " is sleeping\n", 13);
	else if (action == 2 && data->dead == 0)
		write(STDOUT_FILENO, " is eating\n", 11);
	else if (action == 3 && data->dead == 0)
		write(STDOUT_FILENO, " is thinking\n", 13);
	else if (action == 4 && data->dead == 0)
		write(STDOUT_FILENO, " has taken a fork\n", 18);
	else if (action == 5 && data->dead == 1)
	{
		write(STDOUT_FILENO, time, ft_strlen(time));
		write(STDOUT_FILENO, " ", 1);
		write(STDOUT_FILENO, num, ft_strlen(num));
		write(STDOUT_FILENO, " died\n", 6);
	}
	pthread_mutex_unlock(&data->print_mtx);
	free(num);
	free(time);
}