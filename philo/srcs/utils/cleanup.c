#include <stdlib.h>

#include "philo.h"

static void	cleanup_forks(t_data *data)
{
	int	i;

	i = 0;
	if (data->forks != NULL)
	{
		i = 0;
		while (i < data->nb_philos)
		{
			if (data->forks[i].id > 0)
				pthread_mutex_destroy(&data->forks[i].gatekeeper);
			i++;
		}
		free(data->forks);
	}
}

static void	cleanup_philo(t_data *data)
{
	int	i;

	i = 0;
	if (data->philo != NULL)
	{
		i = 0;
		while (i < data->nb_philos)
		{
			if (data->philo[i].id > 0)
				pthread_mutex_destroy(&data->philo[i].eater_mutex);
			i++;
		}
		free(data->philo);
	}
}

void	cleanup(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->philo != NULL || data->forks != NULL)
	{
		pthread_mutex_destroy(&data->mutex_printing);
		pthread_mutex_destroy(&data->mutex_sim_state);
	}
	cleanup_forks(data);
	cleanup_philo(data);
}
