#ifndef PHILO_H
# define PHILO_H

typedef struct s_data
{
	int			nb_meal;
	int			nb_philos;
	int			tt_die;
	int			tt_eat;
	int			tt_sleep;
	long long	start;
}	t_data;

int	parser(int ac, char **av, t_data *data);

#endif
