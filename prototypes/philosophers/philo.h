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
	pthread_mutex_t		print_mtx;
	pthread_mutex_t		death_mtx;
	pthread_t			*threads; // threads

	// death status
	int					dead;
	int					thread_index;

	// time in microseconds
	long unsigned int	no_of_philosophers;
	long unsigned int	time_to_eat;
	long unsigned int	time_to_sleep;
	long unsigned int	time_to_die;
	long unsigned int	no_of_eats;
	long unsigned int	start_time;
	
	int					*forks; // track fork possesion by a philosopher
	// fork[philo_num] = left fork,  fork[philo_num + 1] = right fork
	int					*eat_count; // track the no of times each philosopher has ate
	long unsigned int	*last_ate;
	// track the time each philosopher last ate,
}				t_data;

// struct
void	init_struct(t_data *data, int argc, char **argv);

// actions
void	p_sleep(t_data *data, int philo_num);
void	p_leftfork(t_data *data, int philo_num);
void	p_rightfork(t_data *data, int philo_num);
void	p_eat(t_data *data, int philo_num);
int		check_death(t_data *data, int philo_num);

// print action
void	print_action(t_data *data, long unsigned int curr_time, int philo_num, int action);

// sim
void	simulation(t_data *data, int curr_thread_index);

// utils
int					ft_atoi(const char *s);
size_t				ft_strlen(const char *s);
char				*ft_itoa(int n);
char				*ft_strdup(const char *s);
long unsigned int	get_curr_time(long unsigned int start_time);

# endif