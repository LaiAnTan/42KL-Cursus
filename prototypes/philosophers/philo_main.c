#include "philo.h"

void	create_all_threads(t_data *p, void *(*f)(), void *args)
{
	int		i;

	i = 0;
	p->threads = (pthread_t *) malloc (sizeof(pthread_t) * p->no_of_philosophers);
	while (i < p->no_of_philosophers)
	{
		pthread_create(&p->threads[i], NULL, f, args);
		p->thread_index = i;
		i++;
	}
}

void	join_all_threads(t_data *p)
{
	int		i;

	i = 0;
	while (i < p->no_of_philosophers)
		pthread_join(p->threads[i++], NULL);
}

void	init_mutex(t_data *p)
{
	pthread_mutex_init(&p->mtx, NULL);
	pthread_mutex_init(&p->print_mtx, NULL);
	pthread_mutex_init(&p->death_mtx, NULL);
}

void	destroy_mutex(t_data *p)
{
	pthread_mutex_destroy(&p->mtx);
	pthread_mutex_destroy(&p->print_mtx);
	pthread_mutex_destroy(&p->death_mtx);
}

int	thread_func(void *args)
{
	t_val	tv;
	t_data	*data;
	int		curr_thread_index;

	data = (t_data *) args;
	curr_thread_index = data->thread_index;

	gettimeofday(&tv, NULL);
	data->start_time = ((tv.tv_sec * 1000000) + tv.tv_usec);
	data->last_ate[curr_thread_index - 1] = data->start_time;
	simulation(data, curr_thread_index);
}

int	main(int argc, char **argv)
{
	t_data data;

	if (argc < 5)
		return (0);
	else if (argc > 6)
		return (0);
	init_struct(&data, argc, argv);
	init_mutex(&data);
	create_all_threads(&data, (void *) thread_func,(void *) &data);
	join_all_threads(&data);
	destroy_mutex(&data);
	return (0);
}

/*
gettimeofday
tv.tv_usec -> microseconds
tv.tv_sec -> seconds
second x 1000 = millisecond
microseconds x 0.001 = millisecond
*/