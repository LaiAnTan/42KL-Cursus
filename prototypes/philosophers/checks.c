#include "philo.h"

int	check_total_ate(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->no_of_philosophers)
	{
		pthread_mutex_lock(&data->eat_mtx);
		if (data->eat_count[i] < data->no_of_eats)
		{
			pthread_mutex_unlock(&data->eat_mtx);
			return (FALSE);
		}
		pthread_mutex_unlock(&data->eat_mtx);
		i++;
	}
	return (TRUE);
}

int	check_death(t_data *data, int philo_num)
{
	int					p;
	long unsigned int	diff;
	long unsigned int	curr_time;

	p = philo_num - 1;
	curr_time = get_curr_time(data);
	pthread_mutex_lock(&data->eat_mtx);
	diff = curr_time - data->last_ate[p];
	pthread_mutex_unlock(&data->eat_mtx);
	pthread_mutex_lock(&data->death_mtx);
	if (diff > data->time_to_die)
		data->dead = philo_num;
	pthread_mutex_unlock(&data->death_mtx);
	if (data->dead)
		print_death(data, curr_time, philo_num);
	return (data->dead);
}

int	check_status(t_data *data)
{
	int	philo_num;

	philo_num = 1;
	while (1)
	{
		while (philo_num <= data->no_of_philosophers)
		{
			if (check_death(data, philo_num) || check_total_ate(data))
			{
				data->stop = 1;
				return (philo_num);
			}
			philo_num++;
		}
		philo_num = 1;
	}
	return (0);
}