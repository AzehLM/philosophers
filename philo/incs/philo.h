#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>

typedef struct s_fork
{
	pthread_mutex_t	gatekeeper;
	int				status;
	int				id;
}	t_fork;

typedef struct s_philo
{
	int				eat_counter;
	int				id;
	long long		last_time_eaten;
	pthread_mutex_t	eater_mutex;
	pthread_t		thread;
	struct s_data	*data;
	t_fork			*l_fork;
	t_fork			*r_fork;
}	t_philo;

typedef struct s_data
{
	bool			running;
	int				nb_meal;
	int				nb_philos;
	int				printing_state;
	int				sim_state;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	long long		start;
	pthread_mutex_t	mutex_printing;
	pthread_mutex_t	mutex_sim_state;
	t_fork			*forks;
	t_philo			*philo;
}	t_data;

int			parser(int ac, char **av, t_data *data);

long long	get_time(void);

void		cleanup(t_data *data);

int			init_simulation(t_data *data);

#endif
