/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:15:49 by gueberso          #+#    #+#             */
/*   Updated: 2025/04/16 08:19:39 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "common.h"
#include "philo.h"

static bool	check_death(t_data *data, int i)
{
	time_t	current_time;
	time_t	time_since_meal;
	bool	is_dead;

	current_time = get_time();
	pthread_mutex_lock(&data->philo[i].eater_mutex);
	time_since_meal = current_time - data->philo[i].last_time_eaten;
	is_dead = time_since_meal >= data->tt_die;
	pthread_mutex_unlock(&data->philo[i].eater_mutex);
	if (is_dead)
	{
		pthread_mutex_lock(&data->mutex_sim_state);
		if (data->sim_state == SIM_ON)
		{
			data->sim_state = SIM_OFF;
			printf("%ld %d died\n", \
				current_time - data->start, data->philo[i].id);
		}
		pthread_mutex_unlock(&data->mutex_sim_state);
		return (true);
	}
	return (false);
}

int	check_sim_has_to_end(t_data *data)
{
	int	i;
	int	done_eating;

	i = 0;
	done_eating = 0;
	if (data->nb_meal == -1)
		return (-1);
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->philo[i].eater_mutex);
		if (data->philo[i].eat_counter >= data->nb_meal)
			done_eating++;
		pthread_mutex_unlock(&data->philo[i].eater_mutex);
		i++;
	}
	return (done_eating);
}

static int	check_all_done(t_data *data)
{
	int	done;

	done = check_sim_has_to_end(data);
	if (done == data->nb_philos)
	{
		pthread_mutex_lock(&data->mutex_sim_state);
		data->sim_state = SIM_OFF;
		pthread_mutex_unlock(&data->mutex_sim_state);
		return (1);
	}
	return (0);
}

static int	check_sim_status(t_data *data, int i)
{
	int	state;

	pthread_mutex_lock(&data->mutex_sim_state);
	state = data->sim_state;
	pthread_mutex_unlock(&data->mutex_sim_state);
	if (state == SIM_OFF || check_death(data, i))
		return (1);
	return (0);
}

int	monitor_philos(t_data *data)
{
	int	i;
	int	should_stop;

	while (1)
	{
		if (data->nb_meal != -1 && check_all_done(data))
			break ;
		i = -1;
		should_stop = 0;
		while (++i < data->nb_philos && !should_stop)
		{
			if (check_sim_status(data, i))
			{
				should_stop = 1;
				break ;
			}
		}
		if (should_stop)
			break ;
		usleep(1000);
	}
	i = -1;
	while (++i < data->nb_philos)
		pthread_join(data->philo[i].thread, NULL);
	return (0);
}
