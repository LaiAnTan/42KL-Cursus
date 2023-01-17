#include "philo.h"

void	p_sleep(t_data *data, int philo_num)
{
	long unsigned int	curr_time;

	if (data->dead == 1)
		return ;
	curr_time = get_curr_time(data->start_time);
	print_action(data, curr_time, philo_num, 1);
	usleep(data->time_to_sleep);
	curr_time = get_curr_time(data->start_time);
	print_action(data, curr_time, philo_num, 3);
}

void	p_leftfork(t_data *data, int philo_num)
{
	int					p;
	long unsigned int	curr_time;

	if (data->dead == 1)
		return ;
	p = philo_num - 1;
	curr_time = get_curr_time(data->start_time);
	pthread_mutex_lock(&data->mtx);
	if (data->forks[p] == 0)
		data->forks[p] = philo_num;
	pthread_mutex_unlock(&data->mtx);
	print_action(data, curr_time, philo_num, 4);
}

void	p_rightfork(t_data *data, int philo_num)
{
	long unsigned int	curr_time;

	if (data->dead == 1)
		return ;
	curr_time = get_curr_time(data->start_time);
	pthread_mutex_lock(&data->mtx);
	if (philo_num == data->no_of_philosophers && data->forks[0] == 0)
		data->forks[0] = philo_num;
	else if (data->forks[philo_num] == 0)
		data->forks[philo_num] = philo_num;
	pthread_mutex_unlock(&data->mtx);
	print_action(data, curr_time, philo_num, 4);
}

void	p_eat(t_data *data, int philo_num)
{
	int					p;
	long unsigned int	curr_time;

	if (data->dead == 1)
		return ;
	curr_time = get_curr_time(data->start_time);
	p = philo_num - 1;
	if ((data->forks[p] == philo_num && data->forks[philo_num] == philo_num) || (data->no_of_philosophers == philo_num && data->forks[p] == philo_num && data->forks[0] == philo_num))
	{
		print_action(data, curr_time, philo_num, 2);
		usleep(data->time_to_eat);
		if (philo_num == data->no_of_philosophers)
			data->forks[0] = 0;
		else
			data->forks[p] = 0;
		data->forks[philo_num] = 0;
		data->last_ate[p] = curr_time;
		data->eat_count[p] += 1;
	}
}

int	check_death(t_data *data, int philo_num)
{
	int					p;
	long unsigned int	diff;
	long unsigned int	curr_time;

	p = philo_num - 1;
	curr_time = get_curr_time(data ->start_time);
	diff = curr_time - data->last_ate[p];
	pthread_mutex_lock(&data->death_mtx);
	if (diff > data->time_to_die)
		data->dead = 1;
	if (data->dead && !data->stop)
		print_action(data, curr_time, philo_num, 5);
	pthread_mutex_unlock(&data->death_mtx);
	return (data->dead);
}