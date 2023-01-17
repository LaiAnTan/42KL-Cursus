#include "philo.h"

int	check_total_ate(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->no_of_philosophers)
	{
		if (data->eat_count[i] < data->no_of_eats)
			return (0);
		i++;
	}
	return (1);
}

int	check_status(t_data *data)
{
	int	philo_num;

	philo_num = 0;
	while (1)
	{
		while (philo_num++ <= data->no_of_philosophers)
		{
			if (check_death(data, philo_num) || check_total_ate(data))
				return (1);
			else if (philo_num > data->no_of_philosophers)
				philo_num = 0;
		}
	}
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
	while (1)
		if (check_status(&data))
			break ;
	join_all_threads(&data);
	destroy_mutex(&data);
	return (0);
}