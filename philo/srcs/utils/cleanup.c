/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:16:07 by gueberso          #+#    #+#             */
/*   Updated: 2025/04/19 12:44:30 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "common.h"
#include "philo.h"

void	join_threads(t_data *data)
{
	int	i;
	int	join_result;

	i = 0;
	join_result = 0;
	while (i < data->nb_philos)
	{
		join_result = pthread_join(data->philo[i].thread, NULL);
		if (join_result != 0)
		{
			printf(JOIN_ERROR THREAD_ID_ERROR, data->philo[i].id, join_result);
			return ;
		}
		i++;
	}
}

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
