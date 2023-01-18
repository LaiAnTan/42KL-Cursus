#include "philo.h"

void	create_all_threads(t_data *p, void *(*f)(), void *args)
{
	int		i;

	i = 0;
	p->threads = (pthread_t *) malloc (sizeof(pthread_t) * p->no_of_philosophers);
	while (i < p->no_of_philosophers)
	{
		pthread_create(&p->threads[i], NULL, f, args);
		pthread_mutex_lock(&p->index_mtx);
		p->thread_index = i;
		pthread_mutex_unlock(&p->index_mtx);
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
	int	i;

	i = 0;
	while (i < p->no_of_philosophers)
		pthread_mutex_init(&p->forks[i++], NULL);
	pthread_mutex_init(&p->eat_mtx, NULL);
	pthread_mutex_init(&p->time_mtx, NULL);
	pthread_mutex_init(&p->write_mtx, NULL);
	pthread_mutex_init(&p->start_mtx, NULL);
	pthread_mutex_init(&p->death_mtx, NULL);
	pthread_mutex_init(&p->index_mtx, NULL);
}

void	destroy_mutex(t_data *p)
{
	int	i;

	i = 0;
	while (i < p->no_of_philosophers)
		pthread_mutex_destroy(&p->forks[i++]);
	pthread_mutex_destroy(&p->eat_mtx);
	pthread_mutex_destroy(&p->time_mtx);
	pthread_mutex_destroy(&p->write_mtx);
	pthread_mutex_destroy(&p->start_mtx);
	pthread_mutex_destroy(&p->death_mtx);
	pthread_mutex_destroy(&p->index_mtx);
}

void	unlock_all_mutex(t_data *data, int index)
{
	if (index == data->no_of_philosophers)
		pthread_mutex_unlock(&data->forks[0]);
	else
		pthread_mutex_unlock(&data->forks[index]);
	pthread_mutex_unlock(&data->forks[index - 1]);

	// pthread_mutex_unlock(&data->pa_mtx);
	// pthread_mutex_unlock(&data->pd_mtx);
	// pthread_mutex_unlock(&data->time_mtx);
	// pthread_mutex_unlock(&data->action_mtx);
	// pthread_mutex_unlock(&data->death_mtx);
}