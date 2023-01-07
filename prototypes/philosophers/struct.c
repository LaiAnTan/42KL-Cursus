#include "philo.h"

void	init_struct(t_data *p, int argc, char **argv)
{
	int			i;
	t_val		tv;

	p->no_of_philosophers = ft_atoi(argv[1]);
	p->time_to_die = ft_atoi(argv[2]);
	p->time_to_eat = ft_atoi(argv[3]);
	p->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		p->no_of_eats = ft_atoi(argv[5]);
	else
		p->no_of_eats = 0;
	gettimeofday(&tv, NULL);
	p->start_time = ((tv.tv_sec * 1000000) + tv.tv_usec);
	printf("master start time: %ld\n", p->start_time);
	p->death = 0;
	if (p->no_of_philosophers == 0 || p->time_to_die == 0 || p->time_to_eat == 0 || p->time_to_sleep == 0)
		exit(0);
	p->forks = (int *) malloc (sizeof(int) * p->no_of_philosophers);
	p->eat_count = (int *) malloc (sizeof(int) * p->no_of_philosophers);
	p->last_ate = (long unsigned int *) malloc (sizeof(long unsigned int) * p->no_of_philosophers);
	i = -1;
	while (++i < p->no_of_philosophers)
	{
		p->forks[i] = 0;
		p->eat_count[i] = 0;
		p->last_ate[i] = p->start_time;
	}
}