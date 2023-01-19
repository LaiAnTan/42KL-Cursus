#include "philo.h"

int	init_struct(t_data *p, int argc, char **argv)
{
	int			i;
	t_val		tv;

	p->no_of_philosophers = ft_atoi(argv[1]);
	p->time_to_die = ft_atoi(argv[2]) * 1000;
	p->time_to_eat = ft_atoi(argv[3]) * 1000;
	p->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		p->no_of_eats = ft_atoi(argv[5]);
	else
		p->no_of_eats = 0;
	p->dead = 0;
	p->start = 0;
	p->stop = 0;
	p->thread_index = 0;
	if (p->no_of_philosophers == 0 || p->time_to_die == 0 || p->time_to_eat == 0 || p->time_to_sleep == 0)
		return (-1);
	p->forks = (pthread_mutex_t *) malloc (sizeof(pthread_mutex_t) * p->no_of_philosophers);
	p->eat_count = (int *) malloc (sizeof(int) * p->no_of_philosophers);
	p->last_ate = (long unsigned int *) malloc (sizeof(long unsigned int) * p->no_of_philosophers);
	i = -1;
	while (++i < p->no_of_philosophers)
		p->eat_count[i] = 0;
	return (0);
}

long unsigned int get_curr_time(t_data *data)
{
	t_val				tv;
	long unsigned int	time;

	pthread_mutex_lock(&data->time_mtx);
	gettimeofday(&tv, NULL);
	time = ((tv.tv_sec * 1000000) + tv.tv_usec - data->start_time) / 1000;
	pthread_mutex_unlock(&data->time_mtx);
	return (time);	//milli
}