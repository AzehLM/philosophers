#include <string.h>
#include <stdlib.h>

#include "philo.h"
#include "common.h"

static int	init_data_mutexes(t_data *data);
static int	init_data(t_data *data);
static int	init_forks(t_data *data);
static int	init_philo(t_data *data);


int	init_simulation(t_data *data)
{
	if (init_data(data) == -1)
		return (-1);
	if (init_forks(data) == -1)
	{
		// free && cleanup data;
		return (-1);
	}
	if (init_philo(data) == -1)
	{
		// free && cleanup data && FORKS
		return (-1);
	}
	return (0);
}

static int	init_data(t_data *data)
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
	if (init_data_mutexes(data) == -1)
	{
		free(data->forks);
		free(data->philo);
		return (-1);
	}
	return (0);
}

static int	init_data_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->mutex_printing, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->sim_state, NULL) != 0)
	{
		pthread_mutex_destroy(&data->mutex_printing);
		return (-1);
	}
	return (0);
}

static int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		data->forks[i].id = i + 1;
		data->forks[i].status = FREE;
		if (pthread_mutex_init(&data->forks[i].gatekeeper, NULL) != 0)
		{
			i--;
			while (i > 0)
			{
				pthread_mutex_destroy(&data->forks[i].gatekeeper);
				i--;
			}
			free(data->forks);
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		data->philo[i].l_fork = &data->forks[i];
		data->philo[i].r_fork = &data->forks[i + 1/* random value for now but for real: WHICH ONE*/];
		data->philo[i].id = i + 1;
		data->philo[i].eat_counter = 0;
		data->philo[i].data = data;
		if (pthread_mutex_init(&data->philo[i].eater_mutex, NULL) != 0)
		{
			i--;
			while (i > 0)
			{
				pthread_mutex_destroy(&data->philo[i].eater_mutex);
				i--;
			}
			free(data->philo);
			return (-1);
		}
		i++;
	}
	return (0);
}
