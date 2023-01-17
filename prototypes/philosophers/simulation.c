#include "philo.h"

void	simulation(t_data *data, int curr_thread_index)
{
	int	philo_num;

	data->stop = 0;
	philo_num = data->thread_index + 1;
	while (1)
	{
		if (data->dead == 1)
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