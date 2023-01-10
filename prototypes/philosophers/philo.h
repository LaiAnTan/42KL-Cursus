#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

typedef struct timeval t_val;

typedef struct s_data
{
	pthread_mutex_t		mtx;
	pthread_t			*threads; // threads

	
	unsigned int		no_of_philosophers;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	unsigned int		time_to_die;
	unsigned int		no_of_eats;
	unsigned int		death;
	long unsigned int	start_time; // in microseconds
	
	int					*forks; // track fork possesion by a philosopher
	// fork[philo_num] = left fork,  fork[philo_num + 1] = right fork
	int					*eat_count; // track the no of times each philosopher has ate
	long unsigned int	*last_ate; // track the time each philosopher last ate in ms
}				t_data;

// struct
void	init_struct(t_data *data, int argc, char **argv);

// actions
void	p_sleep(t_data *data, int philo_num);
void	p_leftfork(t_data *data, int philo_num);
void	p_rightfork(t_data *data, int philo_num);
void	p_eat(t_data *data, int philo_num);

// sim
void	simulation(t_data *data);

// utils
int					ft_atoi(const char *s);
long unsigned int	get_curr_time(long unsigned int start_time);

# endif