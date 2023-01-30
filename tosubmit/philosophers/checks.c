/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:57:46 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/30 15:24:16 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_total_ate(t_data *data)
{
	int	i;
	int	eat_count;

	i = 0;
	if (data->no_of_eats == 0)
		return (FALSE);
	while (i < data->no_of_philosophers)
	{
		pthread_mutex_lock(&data->eat_mtx);
		eat_count = data->eat_count[i];
		pthread_mutex_unlock(&data->eat_mtx);
		if (eat_count < data->no_of_eats)
			return (FALSE);
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
				pthread_mutex_lock(&data->stop_mtx);
				data->stop = 1;
				pthread_mutex_unlock(&data->stop_mtx);
				return (philo_num);
			}
			philo_num++;
		}
		philo_num = 1;
	}
	return (0);
}
