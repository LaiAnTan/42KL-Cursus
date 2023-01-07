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

void	simulation(t_data *data)
{
	int	i;
	int	cycle;
	int	philo_num;
	int	total;
	
	cycle = 1;
	philo_num = 2;
	total = data->no_of_philosophers;

	while (1)
	{
		if (check_total_ate(data))
			break ;
		while (philo_num <= total)
		{
			// p_check_death(data, philo_num);
			p_leftfork(data, philo_num);
			p_rightfork(data, philo_num);
			p_eat(data, philo_num);
			p_sleep(data, philo_num);
			philo_num += 2;
		}
		if (cycle % 2 != 0)
			philo_num = 1;
		else
			philo_num = 2;
		cycle++;
		i++;
	}
	return ;
}