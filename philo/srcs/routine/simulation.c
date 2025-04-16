/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:16:05 by gueberso          #+#    #+#             */
/*   Updated: 2025/04/16 08:16:06 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "common.h"

int	check_simulation_state(t_data *data)
{
	int	state;

	pthread_mutex_lock(&data->mutex_sim_state);
	state = data->sim_state;
	pthread_mutex_unlock(&data->mutex_sim_state);
	return (state);
}

int	simulation_start(t_data *data)
{
	int	i;

	i = -1;
	data->sim_state = SIM_ON;
	data->start = get_time();
	while (++i < data->nb_philos)
	{
		data->philo[i].last_time_eaten = data->start;
		if (pthread_create(&data->philo[i].thread, NULL, routine, \
														&data->philo[i]) != 0)
			return (-1);
	}
	return (0);
}
