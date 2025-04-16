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
	int				priority;
	long long		last_time_eaten;
	pthread_mutex_t	eater_mutex;
	pthread_t		thread;
	struct s_data	*data;
	t_fork			*l_fork;
	t_fork			*r_fork;
}	t_philo;

typedef struct s_data
{
	int				nb_meal;
	int				nb_philos;
	int				printing_state;
	int				sim_state;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	time_t			start;
	pthread_mutex_t	mutex_printing;
	pthread_mutex_t	mutex_sim_state;
	t_fork			*forks;
	t_philo			*philo;
}	t_data;

int			parser(int ac, char **av, t_data *data);

void	print_status(t_philo *philo, char *status);

time_t	get_time(void);

void	usleep_enhanced(time_t ms);
int			simulation_start(t_data *data);

void		cleanup(t_data *data);

int			init_simulation(t_data *data);
int			check_simulation_state(t_data *data);

int			check_sim_has_to_end(t_data *data);


void		*routine(void *arg);

int		take_fork(t_philo *philo);

void    release_forks(t_philo *philo);
void    eating(t_philo *philo);
void    sleep_think(t_philo *philo);
int     monitor_philos(t_data *data);

#endif
