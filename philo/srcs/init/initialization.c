#include <string.h>
#include <stdlib.h>

#include "philo.h"

int	init_data(t_data *data)
{
	data->running = true;
	data->start = get_time();
	data->philo = malloc(sizeof(t_philo) * data->nb_philos);
	if (data->philo == NULL)
		return (-1);
	data->forks = malloc(sizeof(t_fork) * data->nb_philos);
	if (data->forks == NULL)
	{
		free(data->philo);
		return (-1);
	}
	memset(data->philo, 0, sizeof(t_philo) * data->nb_philos);
	memset(data->forks, 0, sizeof(t_fork) * data->nb_philos);
	return (0);
}

// int	init_mutex(t_data *data)
// {
// 	int	i;

// 	pthread_mutex_init(&data->philo->eater_mutex, NULL);
// }
