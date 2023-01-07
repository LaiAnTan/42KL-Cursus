#include "philo.h"

void	p_sleep(t_data *data, int philo_num)
{
	long unsigned int	curr_time;

	if (data->forks[philo_num] == philo_num || data ->forks[philo_num + 1] == philo_num)
		return ;
	curr_time = get_curr_time(data->start_time);
	printf("%ld %d is sleeping\n", curr_time, philo_num);
	usleep(data->time_to_sleep);
	printf("%ld %d is thinking\n", curr_time, philo_num);
}

void	p_leftfork(t_data *data, int philo_num)
{
	long unsigned int	curr_time;

	curr_time = get_curr_time(data->start_time);
	if (data->forks[philo_num - 1] == 0)
	{
		pthread_mutex_lock(&data->mtx);
		data->forks[philo_num - 1] = philo_num;
		pthread_mutex_unlock(&data->mtx);
		printf("%ld %d has taken a fork\n", curr_time, philo_num);
	}
}

void	p_rightfork(t_data *data, int philo_num)
{
	long unsigned int	curr_time;

	curr_time = get_curr_time(data->start_time);
	// case: last philosopher
	if (philo_num == data->no_of_philosophers && data->forks[0] == 0)
	{
		pthread_mutex_lock(&data->mtx);
		data->forks[0] = philo_num;
		pthread_mutex_unlock(&data->mtx);
		printf("%ld %d has taken a fork\n", curr_time, philo_num);
	}
	else if (data->forks[philo_num] == 0)
	{
		pthread_mutex_lock(&data->mtx);
		data->forks[philo_num] = philo_num;
		pthread_mutex_unlock(&data->mtx);
		printf("%ld %d has taken a fork\n", curr_time, philo_num);
	}
}

void	p_eat(t_data *data, int philo_num)
{
	long unsigned int	curr_time;

	if ((data->forks[0] != 0 || data->forks[philo_num] != 0) && (data->forks[philo_num - 1] != 0))
	{
		curr_time = get_curr_time(data->start_time);
		printf("%ld %d is eating\n", curr_time, philo_num);
		usleep(data->time_to_eat);
		// clear right fork
		if (philo_num == data->no_of_philosophers && data->forks[0] != 0)
			data->forks[0] = 0;
		else if (data->forks[philo_num] != 0)
			data->forks[philo_num] = 0;
		// clear left fork
		if (data->forks [philo_num - 1] != 0)
			data->forks[philo_num - 1] = 0;
		data->last_ate[philo_num - 1] = (int) curr_time;
		data->eat_count[philo_num -1] += 1;
	}
}