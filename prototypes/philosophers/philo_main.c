#include "philo.h"

void	create_all_threads(t_data *p, void *(*f)(), void *args)
{
	int		i;

	i = 0;

	p->threads = (pthread_t *) malloc (sizeof(pthread_t) * p->no_of_philosophers);
	while (i < p->no_of_philosophers)
		pthread_create(&p->threads[i++], NULL, f, args);
}

void	*thread_func(void *args)
{
	int		x;

	x = *(int *) args;
	if (x == 0)
		printf("eat\n");
	else if( x== 1)
		printf("sleep\n");
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
	// create_all_threads(&data, thread_func, &val);
	pthread_mutex_destroy(&data.mtx);
}


/*
gettimeofday
tv.tv_usec -> microseconds
tv.tv_sec -> seconds
second x 1000 = millisecond
microseconds x 0.001 = millisecond
*/