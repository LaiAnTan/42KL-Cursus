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

void	simulation(t_data *data, int curr_thread_index)
{
	int	philo_num = data->thread_index + 1;
	
	
	while (!check_death(data, philo_num))
	{
		if (check_total_ate(data))
			break ;
		if (philo_num % 2 == 0)
		{
			p_leftfork(data, philo_num);
			p_rightfork(data, philo_num);
			p_eat(data, philo_num);
			p_sleep(data, philo_num);
		}
		else
		{
			p_sleep(data, philo_num);
			p_leftfork(data, philo_num);
			p_rightfork(data, philo_num);
			p_eat(data, philo_num);
			p_sleep(data, philo_num);
		}
	}
	return ;
}