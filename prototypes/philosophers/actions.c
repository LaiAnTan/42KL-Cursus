#include "philo.h"

void	p_sleep(t_data *data, int philo_num)
{
	unsigned int	curr_time;

	if (data->forks[philo_num] == philo_num || data ->forks[philo_num + 1] == philo_num)
		return ;
	curr_time = get_curr_time(data);
	printf("%d %d is sleeping\n", curr_time, philo_num);
	usleep(data ->time_to_sleep);
}

void	p_leftfork(t_data *data, int philo_num)
{
	unsigned int	curr_time;

	curr_time = get_curr_time(data);
	if (data->forks[philo_num] == 0)
	{
		pthread_mutex_lock(&data->mtx);
		data->forks[philo_num] = philo_num;
		pthread_mutex_unlock(&data->mtx);
		printf("%d %d has taken a fork\n", curr_time, philo_num);
	}
}

void	p_rightfork(t_data *data, int philo_num)
{
	unsigned int	curr_time;

	curr_time = get_curr_time(data);
	if (philo_num + 1 == data->no_of_philosophers && data->forks[0] == 0)
	{
		pthread_mutex_lock(&data->mtx);
		data->forks[0] = philo_num;
		pthread_mutex_unlock(&data->mtx);
		printf("%d %d has taken a fork\n", curr_time, philo_num);
	}
	else if (data->forks[philo_num + 1] == 0)
	{
		pthread_mutex_lock(&data->mtx);
		data->forks[philo_num + 1] = philo_num;
		pthread_mutex_unlock(&data->mtx);
		printf("%d %d has taken a fork\n", curr_time, philo_num);
	}
}

void	p_eat(t_data *data, int philo_num)
{

}