#include "philo.h"

void	simulation(t_data *data, int curr_thread_index)
{
	int					stop_sig;
	int					philo_num;
	int					has_forks;
	long unsigned int	curr_time;

	philo_num = curr_thread_index + 1;
	has_forks = 0;
	if (philo_num % 2 != 0)
	{
		curr_time = get_curr_time(data);
		print_action(data, curr_time, philo_num, 3);
		usleep(data->time_to_eat);
	}
	while (!stop_sig)
	{
		pthread_mutex_lock(&data->stop_mtx);
		stop_sig = data->stop;
		pthread_mutex_unlock(&data->stop_mtx);
		if (has_forks == 0)
		{
			p_leftfork(data, philo_num, &has_forks);
			p_rightfork(data, philo_num, &has_forks);
		}
		if (has_forks == 2)
		{
			p_eat(data, philo_num);
			p_sleep(data, philo_num);
			has_forks = 0;
		}
	}
	return ;
}

int	wait_for_start(t_data *data)
{
	int	rv;

	pthread_mutex_lock(&data->start_mtx);
	rv = data->start;
	pthread_mutex_unlock(&data->start_mtx);
	return (rv);
}

int	thread_func(void *args)
{
	t_val	tv;
	t_data	*data;
	int		curr_thread_index;

	data = (t_data *) args;
	pthread_mutex_lock(&data->write_mtx);
	curr_thread_index = data->thread_index;
	data->thread_index++;
	pthread_mutex_unlock(&data->write_mtx);
	while (!wait_for_start(data)) {}
	pthread_mutex_lock(&data->time_mtx);
	gettimeofday(&tv, NULL);
	data->start_time = ((tv.tv_sec * 1000000) + tv.tv_usec);		//micro
	data->last_ate[curr_thread_index] = data->start_time / 1000;	//milli
	pthread_mutex_unlock(&data->time_mtx);
	simulation(data, curr_thread_index);
	unlock_all_mutex(data, curr_thread_index);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;

	if (argc < 5)
		return (0);
	else if (argc > 6)
		return (0);
	if (init_struct(&data, argc, argv) == -1)
		return (0);
	init_mutex(&data);
	create_all_threads(&data, (void *) thread_func,(void *) &data);
	pthread_mutex_lock(&data.start_mtx);
	data.start = TRUE;
	pthread_mutex_unlock(&data.start_mtx);
	usleep(data.time_to_die);
	check_status(&data);
	join_all_threads(&data);
	destroy_mutex(&data);
	return (0);
}