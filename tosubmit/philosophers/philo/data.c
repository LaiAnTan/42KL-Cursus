/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:44:56 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/19 17:34:50 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_constants(t_data *p, int argc, char **argv)
{
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
	if (p->no_of_philosophers == 0 || p->time_to_die == 0
		|| p->time_to_eat == 0 || p->time_to_sleep == 0)
		return (-1);
	return (0);
}

int	init_struct(t_data *p, int argc, char **argv)
{
	int			i;

	if (init_constants(p, argc, argv) == -1)
		return (-1);
	p->forks = (pthread_mutex_t *) malloc (sizeof(pthread_mutex_t)
			* p->no_of_philosophers);
	if (!p->forks)
		return (-1);
	p->eat_count = (int *) malloc (sizeof(int) * p->no_of_philosophers);
	if (!p->eat_count)
		return (-1);
	p->last_ate = (long unsigned int *) malloc (sizeof(long unsigned int)
			* p->no_of_philosophers);
	if (!p->last_ate)
		return (-1);
	i = -1;
	while (++i < p->no_of_philosophers)
		p->eat_count[i] = 0;
	return (0);
}

long unsigned int	get_curr_time(t_data *data)
{
	t_val				tv;
	long unsigned int	time;

	pthread_mutex_lock(&data->time_mtx);
	gettimeofday(&tv, NULL);
	time = ((tv.tv_sec * 1000000) + tv.tv_usec - data->start_time) / 1000;
	pthread_mutex_unlock(&data->time_mtx);
	return (time);
}

void	free_data(t_data *data)
{
	free(data->forks);
	free(data->eat_count);
	free(data->last_ate);
	free(data->threads);
}

int	error(t_data *data)
{
	write(STDERR_FILENO, "Error\n", 6);
	free_data(data);
	return (-1);
}
