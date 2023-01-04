#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct timeval t_val;

typedef struct s_data
{
	pthread_mutex_t	mtx;

	// all time in ms
	unsigned int	no_of_philosophers;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	time_to_die;
	unsigned int	no_of_eats;
	unsigned int	start_time;
	unsigned int	death;
	
	int			*forks; // track fork possesion by a philosopher
	// fork[philo_num] = left fork,  fork[philo_num + 1] = right fork
	int			*eat_count; // track the no of times each philosopher has ate
	int			*last_ate; // track the time each philosopher last ate in ms
	pthread_t	*threads; // threads
}				t_data;

// struct
void	init_struct(t_data *data, int argc, char **argv);

// actions
void	p_sleep(t_data *data, int philo_num);

// utils
int				ft_atoi(const char *s);
unsigned int	get_curr_time(t_data *data);

# endif