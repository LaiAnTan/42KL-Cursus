#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

# define TRUE 1
# define FALSE 0

typedef struct timeval	t_val;

typedef struct s_data
{
	// threads
	pthread_t			*threads;

	// mutexes
	pthread_mutex_t		eat_mtx;
	pthread_mutex_t		time_mtx;
	pthread_mutex_t		write_mtx;
	pthread_mutex_t		death_mtx;
	pthread_mutex_t		start_mtx;
	pthread_mutex_t		stop_mtx;

	// track fork possesion by a philosopher, fork[philo_num] = left fork,  fork[philo_num + 1] = right fork
	pthread_mutex_t		*forks;

	// status flags
	int					dead;
	int					start;
	int					stop;
	int					thread_index;

	// track the no of times each philosopher has ate
	int					*eat_count;

	// constants (time in microseconds)
	long unsigned int	no_of_eats;
	long unsigned int	no_of_philosophers;
	long unsigned int	time_to_eat;
	long unsigned int	time_to_sleep;
	long unsigned int	time_to_die;
	long unsigned int	start_time;

	// track the time each philosopher last ate
	long unsigned int	*last_ate;
}				t_data;

// thread main
int		thread_func(void *args);

// sim
void	simulation(t_data *data, int curr_thread_index);

// pthread
void	create_all_threads(t_data *p, void *(*f)(), void *args);
void	join_all_threads(t_data *p);
void	init_mutex(t_data *p);
void	destroy_mutex(t_data *p);
void	unlock_all_mutex(t_data *data, int index);

// data
int		init_struct(t_data *data, int argc, char **argv);

long unsigned int	get_curr_time(t_data *data);

// actions
void	p_sleep(t_data *data, int philo_num);
void	p_leftfork(t_data *data, int philo_num, int *forks);
void	p_rightfork(t_data *data, int philo_num, int *forks);
void	p_eat(t_data *data, int philo_num);

// checks
int		check_status(t_data *data);
int		check_death(t_data *data, int philo_num);

// print action
void	print_action(t_data *data, long unsigned int curr_time,
			int philo_num, int action);
void	print_death(t_data *data, long unsigned int curr_time, int philo_num);

// utils
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *s);
char	*ft_itoa(int n);

# endif