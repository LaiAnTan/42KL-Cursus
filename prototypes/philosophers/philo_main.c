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

int	thread_func(void *args)
{
	t_data	*data;
	int		curr_thread_index;

	data = (t_data *) args;
	curr_thread_index = data->thread_index;
	simulation(data, curr_thread_index);
}

int	main(int argc, char **argv)
{
	t_data data;

	if (argc < 5)
		exit(0);
	else if (argc > 6)
		exit(0);
	init_struct(&data, argc, argv);
	pthread_mutex_init(&data.mtx, NULL);
	create_all_threads(&data, (void *) thread_func,(void *) &data);
	join_all_threads(&data);
	pthread_mutex_destroy(&data.mtx);

	return (0);
}

/*
gettimeofday
tv.tv_usec -> microseconds
tv.tv_sec -> seconds
second x 1000 = millisecond
microseconds x 0.001 = millisecond
*/