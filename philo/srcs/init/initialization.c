/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:15:52 by gueberso          #+#    #+#             */
/*   Updated: 2025/08/08 11:45:58 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "philo.h"
#include "common.h"

static bool	init_data_mutexes(t_data *data);
static bool	init_data(t_data *data);
static bool	init_forks(t_data *data);
static bool	init_philo(t_data *data);

bool	init_simulation(t_data *data)
{
	if (!init_data(data))
		return (false);
	if (!init_forks(data))
	{
		cleanup(data);
		return (false);
	}
	if (!init_philo(data))
	{
		cleanup(data);
		return (false);
	}
	return (true);
}

static bool	init_data(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->nb_philos);
	if (data->philo == NULL)
		return (false);
	data->forks = malloc(sizeof(t_fork) * data->nb_philos);
	if (data->forks == NULL)
	{
		free(data->philo);
		return (false);
	}
	memset(data->philo, 0, sizeof(t_philo) * data->nb_philos);
	memset(data->forks, 0, sizeof(t_fork) * data->nb_philos);
	if (!init_data_mutexes(data))
	{
		free(data->forks);
		free(data->philo);
		return (false);
	}
	return (true);
}

static bool	init_data_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->mutex_printing, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->mutex_sim_state, NULL) != 0)
	{
		pthread_mutex_destroy(&data->mutex_printing);
		return (false);
	}
	return (true);
}

static bool	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		data->forks[i].id = i + 1;
		data->forks[i].status = AVAILABLE;
		if (pthread_mutex_init(&data->forks[i].gatekeeper, NULL) != 0)
		{
			i--;
			while (i > 0)
			{
				pthread_mutex_destroy(&data->forks[i].gatekeeper);
				i--;
			}
			pthread_mutex_destroy(&data->mutex_printing);
			pthread_mutex_destroy(&data->mutex_sim_state);
			free(data->forks);
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		data->philo[i].l_fork = &data->forks[i];
		data->philo[i].r_fork = &data->forks[(i + 1) % data->nb_philos];
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
			return (false);
		}
		i++;
	}
	return (true);
}
